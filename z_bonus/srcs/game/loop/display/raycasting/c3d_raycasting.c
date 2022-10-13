/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 20:42:43 by ppajot           ###   ########.fr       */
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
	double	t;
	double	cost;
	double	sint;

	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_WIDTH / (double)WIN_WIDTH;
	t = -d / game->settings.fov;
	//ray.angle.value = atan (-d / game->settings.fov) + game->player.plane.value;
	cost = 1 / sqrt(1 + pow(t, 2));
	sint = t * cost;
	//ray.angle.cos = cos(ray.angle.value);
	//ray.angle.sin = sin(ray.angle.value);
	ray.angle.cos = cost * game->player.plane.cos - sint * game->player.plane.sin;
	ray.angle.sin = sint * game->player.plane.cos + cost * game->player.plane.sin;
	ray.angle.tan = ray.angle.sin / ray.angle.cos;
	ray.x = game->player.pos.x + d * game->player.plane.sin;
	ray.y = game->player.pos.y + d * game->player.plane.cos;
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
	while (i < WIN_HEIGHT)
	{
		dx = i * (double)VIEW_HEIGHT / (double)WIN_HEIGHT;
		dx -= (double)VIEW_HEIGHT / 2;
		game->display.fc_dist[i] = (CASE_SIZE / 2 - game->player.z + dx) * game->settings.fov / dabs(-game->player.z + game->player.updown + dx);
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
