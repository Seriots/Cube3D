/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 22:35:21 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	cast_ray(t_game *game, int i)
{
	double		d;
	t_vector	ray;
	t_wall		wall;

	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH;
	ray.angle = atan (-d / game->settings.fov) + game->player.angle_plane;
	ray.x = game->player.pos.x + d * sin(game->player.angle_plane);
	ray.y = game->player.pos.y + d * cos(game->player.angle_plane);
	wall.face = 0;
	wall.dist = 0;
	wall.dist_from_start = 0;
	intersect_wall(game, ray, &wall);
	display_wall(game, &wall, i);
	return (0);
}

int	fill_fc_dist(t_game *game)
{
	int	i;
	double	dx;

	i = 0;
	//printf("\n");
	while (i < WIN_HEIGHT)
	{
		dx = i * (double)VIEW_HEIGHT / (double)WIN_HEIGHT;
		dx -= (double)VIEW_HEIGHT / 2;
		game->display.fc_dist[i] = (CASE_SIZE / 2 - game->player.z + dx) * game->settings.fov / dabs(-game->player.z + game->player.updown + dx);
		//printf("i: %i\nfc_dist = %f\n", i, game->display.fc_dist[i]);
		i++;
	}
	return (0);
}

int	raycasting(t_game *game)
{
	int	i;

	i = 0;
	fill_fc_dist(game);
	while (i < WIN_WIDTH)
	{
		cast_ray(game, i);
		i++;
	}
	return (0);
}
