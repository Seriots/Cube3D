/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/18 19:51:56 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

double	get_obj_angle(t_game *game, double x, double y)
{
	double	angle;

	angle = atan(y / x);
	if (x < 0)
		angle += M_PI;
	return (angle);
}

int draw_sprite_vline(t_game *game, t_img_data *img, double dist, int i)
{
	int	j;

	j = game->display.max + 1;
	while (--j > game->display.min && j >= 0)
	{
		if (j > WIN_HEIGHT)
			continue ;
		my_mlx_pixel_put(&game->all_img.screen_img,
			i, j, 0xFFFFFF);
	}
	return (0);
	(void)img;
	(void)dist;
}

int	display_stuff(t_game *game, t_img_data *img, double dist, double angle)
{
	int	vline;
	double	sprite_width;
	int	i;

	vline = -game->settings.fov * tan(angle) * (double)WIN_WIDTH / (double)VIEW_WIDTH + (double)WIN_WIDTH / 2;
	sprite_width = (((double)WIN_WIDTH / (double)VIEW_WIDTH ) * CASE_SIZE / 2) * game->settings.fov / dist;
	i = -sprite_width / 2;
	game->display.d = (vline - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1 / sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown + game->player.z - ((double)CASE_SIZE / 2 - game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown - game->player.z - ((double)CASE_SIZE / 2 + game->player.updown) * game->settings.fov / (game->display.angle * (dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.min *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	while (i < sprite_width / 2)
	{
		draw_sprite_vline(game, img, dist, i + vline);
		i++;
	}
	return (0);
}

int	display_sprite(t_game *game, double x, double y, t_img_data *img)
{
	double	obj_angle;
	double	dist;

	obj_angle = get_obj_angle(game, x - game->display.xfov, y - game->display.yfov);
	if (obj_angle > game->display.left_angle || obj_angle < game->display.right_angle)
		return (0);
	dist = sqrt(pow(x - game->display.xfov, 2) + pow(y - game->display.yfov, 2)) - game->settings.fov / cos(dabs(obj_angle - game->player.plane.value));
	display_stuff(game, img, dist, obj_angle - game->player.plane.value);
}

int	display_all_sprites(t_game *game)
{
	game->display.xfov = game->player.pos.x - game->settings.fov * game->player.plane.cos;
	game->display.yfov = game->player.pos.y + game->settings.fov * game->player.plane.sin;
	game->display.left_angle = atan ((((double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + game->player.plane.value;
	game->display.right_angle = atan (-(((WIN_WIDTH - 1) - (double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH) / game->settings.fov) + game->player.plane.value;
	display_sprite(game, 200, 200, &game->all_img.no);
	return (0);
}