/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/19 19:40:56 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "dict.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

#define SPRITE_WIDTH 1 / 3
#define	SPRITE_HEIGHT 1 / 2

double	get_obj_angle(double x, double y)
{
	double	angle;

	angle = atan(y / x);
	if (x < 0)
		angle += M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

unsigned int	get_sprite_color(t_game *game, t_img_data *img, int j, int i, int width)
{
	void	*color;
	int		x;
	int		y;

	x = (i * img->width) / width;
	y = (j * img->height) / (game->display.max - game->display.min);
	color = (img->addr
			+ (y * img->line_length
				+ x * img->bits_per_pixel / 8));
	return (*(unsigned int *)color);
	//(void)game;
	//(void)img;
	//return (0xFFFFFF);
}

int draw_sprite_vline(t_game *game, t_img_data *img, int i, int width)
{
	int	j;
	unsigned int	color;

	j = game->display.min - 1;
	while (++j < WIN_HEIGHT && j < game->display.max)
	{
		if (j < 0)
			continue ;
		//printf("row: %i\n", j);
		color = get_sprite_color(game, img, j - game->display.min, i - game->display.vline + width / 2, width);
		if (color != 0xFF000000)
			my_mlx_pixel_put(&game->all_img.screen_img, i, j, color);
	}
	return (0);
}

int	display_sprite(t_game *game, t_object *obj, double dist, double angle)
{
	double	sprite_width;
	int	i;

	game->display.vline = -game->settings.fov * tan(angle) * (double)WIN_WIDTH / (double)VIEW_WIDTH + (double)WIN_WIDTH / 2;
	sprite_width = (((double)WIN_WIDTH / (double)VIEW_WIDTH ) * obj->width) * game->settings.fov / (dist + game->settings.fov / cos(angle));
	i = -sprite_width / 2;
	game->display.d = (game->display.vline - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1 / sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown + game->player.z - ((double)CASE_SIZE / 2 - game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown - game->player.z - ((double)CASE_SIZE / 2 + game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.min = game->display.max - (game->display.max - game->display.min) * obj->height / CASE_SIZE;
	while (i < sprite_width / 2)
	{
		if (i + game->display.vline >= 0 && i + game->display.vline < WIN_WIDTH)
		{
			//printf("line: %i\n", i + game->display.vline);
			if (game->display.wall_dist[i + game->display.vline] > dist)
				draw_sprite_vline(game, obj->game_img, i + game->display.vline, sprite_width);
		}
		i++;
	}
	return (0);
}

int	check_angle(double angle, double left_angle, double right_angle)
{
	if (angle < left_angle && angle > right_angle)
		return (1);
	if (angle + 2 * M_PI < left_angle && angle + 2 * M_PI > right_angle)
		return (1);
	if (angle - 2 * M_PI < left_angle && angle - 2 * M_PI > right_angle)
		return (1);
	return (0);
}

int	cmp_obj_dist(t_dict *dict1, t_dict *dict2)
{
	t_object *obj1;
	t_object *obj2;

	obj1 = dict1->value;
	obj2 = dict2->value;
	if (obj1->dist > obj2->dist)
		return (-1);
	else if (obj1->dist < obj2->dist)
		return (1);
	return (0);
}

double	get_dist_obj(t_game *game, t_object *obj)
{
	double	dist;

	obj->angle = get_obj_angle(obj->pos.x - game->display.xfov, -obj->pos.y + game->display.yfov);
	//printf("angle: %f, angle left: %f, angle right: %f\n", obj->angle, game->display.left_angle, game->display.right_angle);
	if (check_angle(obj->angle, game->display.left_angle, game->display.right_angle) == 0)
		return (-1.0);
	dist = sqrt(pow(obj->pos.x - game->display.xfov, 2) + pow(obj->pos.y - game->display.yfov, 2));
	if (dist <= game->settings.fov / cos(dabs(obj->angle - game->player.plane.value)))
		return (-1.0);
	dist -= game->settings.fov / cos(dabs(obj->angle - game->player.plane.value));
	return (dist);
}

int	get_all_obj_dist(t_game *game)
{
	t_dict	*tmp;
	t_object	*obj;

	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		obj->dist = get_dist_obj(game, obj);
		tmp = tmp->next;
	}
	return (0);
}

int	display_all_sprites(t_game *game)
{
	t_dict	*tmp;
	t_object	*obj;

	game->display.xfov = game->player.pos.x - game->settings.fov * game->player.plane.cos;
	game->display.yfov = game->player.pos.y + game->settings.fov * game->player.plane.sin;
	game->display.left_angle = /*atan ((((double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + */game->player.plane.value + M_PI / 2;
	game->display.right_angle = /*atan (-(((WIN_WIDTH - 1) - (double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + */game->player.plane.value - M_PI / 2;
	get_all_obj_dist(game);
	dict_sort_fct(&game->map.all_objects, &cmp_obj_dist);
	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && obj->dist >= 0 && obj->is_visible && obj->game_img)
			display_sprite(game, obj, obj->dist, obj->angle - game->player.plane.value);
		tmp = tmp->next;
	}
	return (0);
}