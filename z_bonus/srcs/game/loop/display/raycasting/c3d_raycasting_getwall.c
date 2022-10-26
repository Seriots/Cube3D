/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_getwall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:39:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 17:21:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_settings.h"
#include "c3d_object.h"

#include "ft.h"

#include <math.h>

#include <stdio.h>

int	set_dist(double *dist_x, double *dist_y, t_vector pre_pos)
{
	if (pre_pos.angle.cos > 0)
		*dist_x = ((ft_floor(pre_pos.x / CASE_SIZE) + sign(pre_pos.angle.cos))
				* CASE_SIZE - pre_pos.x) / pre_pos.angle.cos;
	else
		*dist_x = ((ft_ceil(pre_pos.x / CASE_SIZE) + sign(pre_pos.angle.cos))
				* CASE_SIZE - pre_pos.x) / pre_pos.angle.cos;
	if (pre_pos.angle.sin > 0)
		*dist_y = ((ft_ceil(pre_pos.y / CASE_SIZE) - sign(pre_pos.angle.sin))
				* CASE_SIZE - pre_pos.y) / pre_pos.angle.sin;
	else
		*dist_y = ((ft_floor(pre_pos.y / CASE_SIZE) - sign(pre_pos.angle.sin))
				* CASE_SIZE - pre_pos.y) / pre_pos.angle.sin;
	return (0);
}

t_vector	get_next_wall(t_vector pre_pos)
{
	t_vector	result;

	set_dist(&result.x, &result.y, pre_pos);
	result.angle = pre_pos.angle;
	if (dabs(result.x) < dabs(result.y))
	{
		if (pre_pos.angle.cos > 0)
			result.x = (ft_floor(pre_pos.x / CASE_SIZE)
					+ sign(pre_pos.angle.cos)) * CASE_SIZE;
		else
			result.x = (ft_ceil(pre_pos.x / CASE_SIZE)
					+ sign(pre_pos.angle.cos)) * CASE_SIZE;
		result.y = -(result.x - pre_pos.x) * pre_pos.angle.tan + pre_pos.y;
	}
	else
	{
		if (pre_pos.angle.sin > 0)
			result.y = (ft_ceil(pre_pos.y / CASE_SIZE)
					- sign(pre_pos.angle.sin)) * CASE_SIZE;
		else
			result.y = (ft_floor(pre_pos.y / CASE_SIZE)
					- sign(pre_pos.angle.sin)) * CASE_SIZE;
		result.x = -(result.y - pre_pos.y) / pre_pos.angle.tan + pre_pos.x;
	}
	return (result);
}

t_object	*find_door(t_game *game, int i, int j)
{
	t_dict		*tmp;
	t_object	*obj;

	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && !ft_strcmp(obj->tag, DOOR)
			&& (obj->pos.x < i * CASE_SIZE + CASE_SIZE
				&& obj->pos.x >= i * CASE_SIZE) && (obj->pos.y < j * CASE_SIZE
					+ CASE_SIZE && obj->pos.y >= j * CASE_SIZE))
			return (obj);
		tmp = tmp->next;
	}
	return (0);
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
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE]
				== '2')
			if (find_door(game, ((int)vec.x + 1) / CASE_SIZE, ((int)vec.y) / CASE_SIZE)->face == 'W')
				wall->face = 'w';
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE]
				== '2')
			if (find_door(game, ((int)vec.x - 1) / CASE_SIZE, ((int)vec.y) / CASE_SIZE)->face == 'E')
				wall->face = 'e';
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
		if (map->map[((int)vec.y + 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
				== '2')
			if (find_door(game, ((int)vec.x) / CASE_SIZE, ((int)vec.y + 1) / CASE_SIZE)->face == 'N')
				wall->face = 'n';
		if (map->map[((int)vec.y - 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
				== '2')
			if (find_door(game, ((int)vec.x) / CASE_SIZE, ((int)vec.y - 1) / CASE_SIZE)->face == 'S')
				wall->face = 's';
	}
	return (wall->face);
}

int	intersect_wall(t_game *game, t_vector ray, t_wall *wall, int i)
{
	t_vector	next_inter;
	char		is_wall;
	int			j;

	is_wall = 0;
	j = 0;
	next_inter = ray;
	while (!is_wall)
	{
		next_inter = get_next_wall(next_inter);
		is_wall = check_wall(game, &game->map, next_inter, wall);
		if (is_wall && ft_tolower(is_wall) == is_wall)
		{
			wall->dist = sqrt(pow(ray.x - next_inter.x, 2)
			+ pow(ray.y - next_inter.y, 2));
			game->display.doors[j][i].door = *wall;
			game->display.doors[j][i].need_display = 1;
			if (is_wall == 's')
				game->display.doors[j][i].img = find_door(game, next_inter.x / CASE_SIZE, next_inter.y / CASE_SIZE - 1)->game_img;
			else if (is_wall == 'e')
				game->display.doors[j][i].img = find_door(game, next_inter.x / CASE_SIZE - 1, next_inter.y / CASE_SIZE)->game_img;
			else
				game->display.doors[j][i].img = find_door(game, next_inter.x / CASE_SIZE, next_inter.y / CASE_SIZE)->game_img;
			j++;
			wall->face = 0;
			is_wall = 0;
		}
	}
	wall->dist = sqrt(pow(ray.x - next_inter.x, 2)
			+ pow(ray.y - next_inter.y, 2));
	return (0);
}
