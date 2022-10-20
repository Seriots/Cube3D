/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_raycasting_getwall.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:39:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 10:29:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdio.h>

int	start_intersect_wall(t_game *game, t_vector ray, t_wall *wall)
{
	t_vector	next_inter;
	char		is_wall;

	is_wall = 0;
	next_inter = ray;
	while (!is_wall)
	{
		next_inter = get_next_wall(next_inter);
		is_wall = check_wall(game, &game->start_map.map, next_inter, wall);
	}
	wall->dist = sqrt(pow(ray.x - next_inter.x, 2)
			+ pow(ray.y - next_inter.y, 2));
	return (0);
}
