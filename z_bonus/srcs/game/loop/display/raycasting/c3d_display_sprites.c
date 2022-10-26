/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/26 12:40:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_object.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

#define SPRITE_WIDTH 1 / 3
#define	SPRITE_HEIGHT 1 / 2

unsigned int	damaged_ghost(t_object *obj, unsigned int color)
{
	double	damage;
	double	max;
	int		r;

	max = 100;
	damage = obj->use_count / (double)obj->use_max * max;
	
	r = (int)(color >> 16) + (int)damage;
	if (r > 255)
		r = 255;
	return ((r << 16) + (color & 0x00FF00) + (color & 0x0000FF));
}

unsigned int	get_sprite_color(t_game *game, t_object *obj, t_point p, int width)
{
	void	*color;
	int		x;
	int		y;

	x = (p.x * obj->game_img->width) / width;
	y = (p.y * obj->game_img->height) / (game->display.max - game->display.min);
	color = (obj->game_img->addr
			+ (y * obj->game_img->line_length
				+ x * obj->game_img->bits_per_pixel / 8));
	if (*(unsigned int *)color != 0xFF000000 && !ft_strcmp(obj->tag, GHOST))
		return (damaged_ghost(obj, *(unsigned int *)color));
	else
		return (*(unsigned int *)color);
}

int draw_sprite_vline(t_game *game, t_object *obj, int i, int width)
{
	int				j;
	t_point			p;
	t_point			p2;
	unsigned int	color;

	j = game->display.min - 1;
	while (++j < WIN_HEIGHT && j < game->display.max)
	{
		if (j < 0)
			continue ;
		p2.x = i;
		p2.y = j;
		p.x = i - game->display.vline + width / 2;
		p.y = j - game->display.min;
		color = get_sprite_color(game, obj, p, width);
		if (color != 0xFF000000)
			my_mlx_pixel_put(&game->all_img.screen_img, i, j, shade_pixel(game, color, obj->dist, p2));
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
				draw_sprite_vline(game, obj, i + game->display.vline, sprite_width);
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