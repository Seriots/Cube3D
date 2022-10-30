/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_getwall.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:39:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/30 21:49:19 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "c3d_loop.h"

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

int	intersect_wall_display(t_game *game, t_wall *wall, t_vector *ray,
	t_intwall *intwall)
{
	wall->dist = sqrt(pow(ray->x - intwall->next_inter.x, 2)
			+ pow(ray->y - intwall->next_inter.y, 2));
	game->display.doors[intwall->i].door_tab[intwall->j].door = *wall;
	game->display.doors[intwall->i].door_tab[intwall->j].need_display = 1;
	if (intwall->is_wall == 's')
		game->display.doors[intwall->i].door_tab[intwall->j].img = find_door(game,
				intwall->next_inter.x / CASE_SIZE, intwall->next_inter.y
				/ CASE_SIZE - 1)->game_img;
	else if (intwall->is_wall == 'e')
		game->display.doors[intwall->i].door_tab[intwall->j].img = find_door(game,
				intwall->next_inter.x / CASE_SIZE - 1,
				intwall->next_inter.y / CASE_SIZE)->game_img;
	else
		game->display.doors[intwall->i].door_tab[intwall->j].img = find_door(game,
				intwall->next_inter.x / CASE_SIZE,
				intwall->next_inter.y / CASE_SIZE)->game_img;
	return (0);
}

int	intersect_wall(t_game *game, t_vector ray, t_wall *wall, int i)
{
	t_intwall	intwall;

	intwall.is_wall = 0;
	intwall.j = 0;
	intwall.i = i;
	intwall.next_inter = ray;
	while (!intwall.is_wall)
	{
		intwall.next_inter = get_next_wall(intwall.next_inter);
		intwall.is_wall = check_wall(game, &game->map,
				intwall.next_inter, wall);
		if (intwall.is_wall && ft_tolower(intwall.is_wall) == intwall.is_wall)
		{
			intersect_wall_display(game, wall, &ray, &intwall);
			if (i == WIN_WIDTH && game->display.doors[intwall.i].door_tab[intwall.j].img
				!= &game->all_img.all_door_img[DOOR_NB_IMAGE - 1])
				break ;
			intwall.j++;
			wall->face = 0;
			intwall.is_wall = 0;
		}
	}
	game->display.doors[intwall.i].door_max = intwall.j;
	wall->dist = sqrt(pow(ray.x - intwall.next_inter.x, 2)
			+ pow(ray.y - intwall.next_inter.y, 2));
	return (0);
}
