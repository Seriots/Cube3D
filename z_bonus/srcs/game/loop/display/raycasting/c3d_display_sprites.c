/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/19 03:56:21 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

#define SPRITE_WIDTH 1 / 8
#define	SPRITE_HEIGHT 1 / 16

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
		if (color)
			my_mlx_pixel_put(&game->all_img.screen_img,
				i, j, color);
	}
	return (0);
}

int	display_stuff(t_game *game, t_img_data *img, double dist, double angle)
{
	double	sprite_width;
	int	i;

	game->display.vline = -game->settings.fov * tan(angle) * (double)WIN_WIDTH / (double)VIEW_WIDTH + (double)WIN_WIDTH / 2;
	sprite_width = (((double)WIN_WIDTH / (double)VIEW_WIDTH ) * CASE_SIZE * SPRITE_WIDTH) * game->settings.fov / (dist + game->settings.fov / cos(angle));
	i = -sprite_width / 2;
	game->display.d = (game->display.vline - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1 / sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown + game->player.z - ((double)CASE_SIZE / 2 - game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown - game->player.z - ((double)CASE_SIZE / 2 + game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.min = game->display.max - (game->display.max - game->display.min) * SPRITE_HEIGHT;
	while (i < sprite_width / 2)
	{
		if (i + game->display.vline >= 0 && i + game->display.vline < WIN_WIDTH)
		{
			//printf("line: %i\n", i + game->display.vline);
			if (game->display.wall_dist[i + game->display.vline] > dist)
				draw_sprite_vline(game, img, i + game->display.vline, sprite_width);
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

int	display_sprite(t_game *game, double x, double y, t_img_data *img)
{
	double	obj_angle;
	double	dist;

	obj_angle = get_obj_angle(x - game->display.xfov, -y + game->display.yfov);
	//printf("angle: %f, angle left: %f, angle right: %f\n", obj_angle, game->display.left_angle, game->display.right_angle);
	if (check_angle(obj_angle, game->display.left_angle, game->display.right_angle) == 0)
		return (0);
	dist = sqrt(pow(x - game->display.xfov, 2) + pow(y - game->display.yfov, 2));
	if (dist <= game->settings.fov / cos(dabs(obj_angle - game->player.plane.value)))
		return (0);
	dist -= game->settings.fov / cos(dabs(obj_angle - game->player.plane.value));
	//printf("dist: %f, x: %f, y: %f\n", dist, game->player.pos.x, game->player.pos.y);
	display_stuff(game, img, dist, obj_angle - game->player.plane.value);
	return (0);
}

int	display_all_sprites(t_game *game)
{
	game->display.xfov = game->player.pos.x - game->settings.fov * game->player.plane.cos;
	game->display.yfov = game->player.pos.y + game->settings.fov * game->player.plane.sin;
	game->display.left_angle = /*atan ((((double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + */game->player.plane.value + M_PI / 2;
	game->display.right_angle = /*atan (-(((WIN_WIDTH - 1) - (double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + */game->player.plane.value - M_PI / 2;
	display_sprite(game, 100, 100, &game->all_img.ph);
	return (0);
}