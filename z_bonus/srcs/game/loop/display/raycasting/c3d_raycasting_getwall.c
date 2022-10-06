/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_getwall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:39:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_settings.h"

#include <math.h>

int	set_dist(double *dist_x, double *dist_y, t_vector pre_pos)
{
	if (cos(pre_pos.angle) > 0)
		*dist_x = ((floor(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle)))
				* CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);
	else
		*dist_x = ((ceil(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle)))
				* CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);
	if (sin(pre_pos.angle) > 0)
		*dist_y = ((ceil(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle)))
				* CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	else
		*dist_y = ((floor(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle)))
				* CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	return (0);
}

t_vector	get_next_wall(t_vector pre_pos)
{
	t_vector	result;

	set_dist(&result.x, &result.y, pre_pos);
	if (dabs(result.x) < dabs(result.y))
	{
		if (cos(pre_pos.angle) > 0)
			result.x = (floor(pre_pos.x / CASE_SIZE)
					+ sign(cos(pre_pos.angle))) * CASE_SIZE;
		else
			result.x = (ceil(pre_pos.x / CASE_SIZE)
					+ sign(cos(pre_pos.angle))) * CASE_SIZE;
		result.y = (result.x - pre_pos.x) * -1 * tan(pre_pos.angle) + pre_pos.y;
	}
	else
	{
		if (sin(pre_pos.angle) > 0)
			result.y = (ceil(pre_pos.y / CASE_SIZE)
					- sign(sin(pre_pos.angle))) * CASE_SIZE;
		else
			result.y = (floor(pre_pos.y / CASE_SIZE)
					- sign(sin(pre_pos.angle))) * CASE_SIZE;
		result.x = (result.y - pre_pos.y) * -1 / tan(pre_pos.angle) + pre_pos.x;
	}
	result.angle = pre_pos.angle;
	return (result);
}

int	check_wall(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	(void)game;
	if (vec.x - (int)vec.x == 0 && (int)vec.x % CASE_SIZE == 0)
	{
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE]
				== '1')
			wall->face = 'W';
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE]
				== '1')
			wall->face = 'E';
		wall->dist_from_start = vec.y;
	}
	else
	{
		if (map->map[((int)vec.y + 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
				== '1')
			wall->face = 'N';
		if (map->map[((int)vec.y - 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
				== '1')
			wall->face = 'S';
		wall->dist_from_start = vec.x;
	}
	return (wall->face);
}

int	intersect_wall(t_game *game, t_vector ray, t_wall *wall)
{
	t_vector	next_inter;
	char		is_wall;

	is_wall = 0;
	next_inter = ray;
	while (!is_wall)
	{
		next_inter = get_next_wall(next_inter);
		is_wall = check_wall(game, &game->map, next_inter, wall);
	}
	wall->dist = sqrt(pow(ray.x - next_inter.x, 2)
			+ pow(ray.y - next_inter.y, 2));
	return (0);
}
