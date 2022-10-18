/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/18 01:26:30 by pierre-yves      ###   ########.fr       */
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

int	display_sprite(t_game *game, double x, double y, t_img_data *img)
{
	double	obj_angle;

	obj_angle = get_obj_angle(game, x - game->display.xfov, y - game->display.yfov);
	if (obj_angle > game->display.left_angle || obj_angle < game->display.right_angle)
		return (0);
	
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