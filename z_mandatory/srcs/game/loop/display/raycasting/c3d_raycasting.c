/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 13:14:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "mlx.h"

#include <math.h>

int	cast_ray(t_game *game, int i)
{
	double		d;
	t_vector	ray;
	t_wall		wall;
	int			l;

	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_SCREEN / (double)WIN_WIDTH;
	ray.angle = atan (-d / game->settings.fov) + game->player.rot;
	ray.x = game->player.pos.x + d * sin(game->player.rot);
	ray.y = game->player.pos.y + d * cos(game->player.rot);
	wall.face = 0;
	wall.dist = 0;
	wall.dist_from_start = 0;
	intersect_wall(game, ray, &wall);
	l = 0;
	while (l < QUALITY)
		display_wall(game, &wall, i + l++);
	return (0);
}

int	raycasting(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH)
	{
		if (i % QUALITY == 0)
			cast_ray(game, i);
		i++;
	}
	return (0);
}
