/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 14:11:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	start_cast_ray(t_game *game, int i)
{
	double		d;
	t_vector	ray;
	t_wall		wall;
	double		t;
	t_coord		angle;

	d = (i - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	t = -d / game->settings.fov;
	angle.x = 1 / sqrt(1 + pow(t, 2));
	angle.y = t * angle.x;
	ray.angle.cos = angle.x * game->start_map.player.plane.cos - angle.y
		* game->start_map.player.plane.sin;
	ray.angle.sin = angle.y * game->start_map.player.plane.cos + angle.x
		* game->start_map.player.plane.sin;
	ray.angle.tan = ray.angle.sin / ray.angle.cos;
	ray.angle.value = 0;
	ray.x = game->start_map.player.pos.x + d * game->start_map.player.plane.sin;
	ray.y = game->start_map.player.pos.y + d * game->start_map.player.plane.cos;
	wall = (t_wall){.dist = 0, .dist_from_start = 0, .face = 0};
	start_intersect_wall(game, ray, &wall);
	game->display.ray = ray;
	start_display_wall(game, &wall, i);
	game->display.wall_dist[i] = wall.dist;
	return (0);
}

int	start_fill_fc_dist(t_game *game)
{
	int		i;
	double	dx;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		dx = i * (double)VIEW_HEIGHT / (double)WIN_HEIGHT;
		dx -= (double)VIEW_HEIGHT / 2;
		if (-game->start_map.player.z + game->start_map.player.updown + dx < 0)
			game->display.fc_dist[i]
				= (CASE_SIZE / 2 - game->start_map.player.z + dx)
				* game->settings.fov / (game->start_map.player.z
					- game->start_map.player.updown - dx);
		else
			game->display.fc_dist[i]
				= (CASE_SIZE / 2 + game->start_map.player.z - dx)
				* game->settings.fov / (-game->start_map.player.z
					+ game->start_map.player.updown + dx);
		i++;
	}
	game->display.ce = &game->all_img.start_ce;
	game->display.fl = &game->all_img.start_fl;
	return (0);
}

int	start_raycasting(t_game *game)
{
	int	i;

	i = 0;
	start_fill_fc_dist(game);
	while (i < WIN_WIDTH)
	{
		start_cast_ray(game, i);
		i++;
	}
	return (0);
}
