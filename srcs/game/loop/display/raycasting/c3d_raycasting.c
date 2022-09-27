/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 18:57:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdio.h>

t_vector	get_next_wall(t_game *game, t_vector pre_pos)
{
	t_vector	result;
	double	dist_x;
	double	dist_y;
	
	(void)game;
	dist_x = (((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.x) * cos(pre_pos.angle);	
	dist_y = (((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.y) * sin(pre_pos.angle);	
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

int	check_wall(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	(void)game;
	printf("search: %d %d, max: %d %d\n", ((int)vec.y + 1) / CASE_SIZE, (int)vec.x / CASE_SIZE, map->height, map->width);
	if ((int)vec.x - (int)vec.x / CASE_SIZE == 0)
	{
		if (map->map[(int)vec.y / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE] == '1') 
			wall->face = 'W';
		if (map->map[(int)vec.y / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE] == '1')
			wall->face = 'E';
		wall->dist_from_start = (int)vec.y - (int)vec.y / CASE_SIZE;
	}
	else
	{
		if (map->map[((int)vec.y + 1) / CASE_SIZE][(int)vec.x / CASE_SIZE] == '1') 
			wall->face = 'S';
		if (map->map[((int)vec.y - 1) / CASE_SIZE][(int)vec.x / CASE_SIZE] == '1')
			wall->face = 'N';
		wall->dist_from_start = (int)vec.x - (int)vec.x / CASE_SIZE;
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
		next_inter = get_next_wall(game, next_inter);
		is_wall = check_wall(game, &game->map, next_inter, wall);
	}
	wall->dist = sqrt(pow(ray.x - next_inter.x, 2) + pow(ray.y - next_inter.y, 2));
	return (0);
}

int	get_pixel_color(t_game *game, t_wall *wall, int y)
{
	if (y < tan(VIEW_SIZE) * wall->dist - WIN_HEIGHT * CASE_SIZE / (2 * 2 * wall->dist * tan(VIEW_SIZE)))
		return (game->map.c);
	else if (y > WIN_HEIGHT - (tan(VIEW_SIZE) * wall->dist - WIN_HEIGHT * CASE_SIZE / (2 * 2 * wall->dist * tan(VIEW_SIZE))))
		return (game->map.f);
	else
	{
		if (wall->face == 'N')
			return (0x00FFFFFF);
		if (wall->face == 'S')
			return (0x00D300FF);
		if (wall->face == 'E')
			return (0x00D3FF00);
		return (0x00FFD300);
	}
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	int	j;

	j = 0;
	while (j < WIN_HEIGHT)
	{
		//printf ("y: %d, limit: %f\n", j, tan(VIEW_SIZE) * wall->dist - (double)(CASE_SIZE / 2));
		my_mlx_pixel_put(&game->all_img.screen_img, i, j, get_pixel_color(game, wall, j));  
		j++;
	}
	return (0);
}

int	cast_ray(t_game *game, int i)
{
	double 		d;
	t_vector	ray;
	t_wall		wall;

	printf("i = %d\n", i);
	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_SCREEN / (double)WIN_WIDTH;
	ray.angle = atan (d / game->settings.fov) + game->player.rot;
	ray.x = game->player.pos.x + d * sin(ray.angle);
	ray.y = game->player.pos.y - d * cos(ray.angle);
	printf("player rot: %f, ray angle: %f\n", game->player.rot, ray.angle);
	//printf("d: %f\nray: %f %f %f\n", d, ray.x / CASE_SIZE, ray.y / CASE_SIZE, ray.angle);
	//printf("%f\n", wall.dist);
	wall.face = 0;
	wall.dist = 0;
	wall.dist_from_start = 0;
	intersect_wall(game, ray, &wall);
	display_wall(game, &wall, i);
	return (0);
}

int	raycasting(t_game *game)
{
	int i;

	i = -1;	
	while (++i < 200) //
		cast_ray(game, i);
	return (0);
}