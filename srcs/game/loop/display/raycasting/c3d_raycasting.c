/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 16:34:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include <math.h>

t_vector	get_next_wall(t_game *game, t_vector pre_pos)
{
	t_vector	result;
	double	dist_x;
	double	dist_y;
	
	dist_x = (((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);	
	dist_y = (((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);	
	if (dist_x < dist_y)
	{
		dist_x = ((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE;	
		dist_y = (((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.x) * tan(pre_pos.angle) + pre_pos.y; 
	}
	else
	{
		dist_y = ((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE;	
		dist_x = (((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.y) / tan(pre_pos.angle) + pre_pos.x;
	}
	result.angle = pre_pos.angle;
	result.x = dist_x;
	result.y = dist_y;
	return (result);
}

t_wall	check_wall(t_game *game, t_map *map, t_vector vec)
{
	t_wall	wall;

	wall.face = 0;
	wall.dist = 0;
	wall.dist_from_start
	if (vec.x - vec.x / CASE_SIZE == 0)
	{
		
		if (map->map[(int)vec.y / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE] == 1) 
			wall.face = 'E';
		if (map->map[(int)vec.y / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE] == 1)
			wall.face = 'W';
		wall.dist_from_start = vec.y - vec.y / 64
	}
	else
	{
		if (map->map[((int)vec.y + 1) / CASE_SIZE][(int)vec.x / CASE_SIZE] == 1) 
			wall.face = 'S';
		if (map->map[((int)vec.y - 1) / CASE_SIZE][(int)vec.x / CASE_SIZE] == 1)
			wall.face = 'N';
		wall.dist_from_start = vec.x - vec.x / 64
	}
	return (wall);
}

char	intersect_wall(t_game *game, t_vector ray)
{
	t_vector	next_inter;
	char		is_wall;
	
	is_wall = 0;
	next_inter = ray;
	while (!is_wall)
	{
		next_inter = get_next_wall(game, next_inter);
		is_wall = check_wall(game, &game->map, next_inter);
	}
	return (is_wall);
}

int	cast_ray(t_game *game, int i)
{
	float 		d;
	t_vector	ray;
	t_wall		wall;

	d = (i - WIN_WIDTH / 2) * VIEW_SCREEN / WIN_WIDTH;
	ray.angle = atan (d / game->settings.fov) + game->player.rot;
	ray.x = game->player.pos.x - d * sin(ray.angle);
	ray.y = game->player.pos.y + d * cos(ray.angle);
	face = intersect_wall(game, ray);
}

int	raycasting(t_game *game)
{
	int i;

	i = -1;	
	while (++i < WIN_WIDTH)
		cast_ray(i, game);
	return (0);
}