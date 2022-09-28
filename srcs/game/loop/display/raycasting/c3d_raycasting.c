/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 16:59:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdio.h>

int	sign(float x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

double	dabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

t_vector	get_next_wall(t_vector pre_pos)
{
	t_vector	result;
	double	dist_x;
	double	dist_y;
	
	if (cos(pre_pos.angle) > 0)
		dist_x = ((floor(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);	
	else
		dist_x = ((ceil(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);
	if (sin(pre_pos.angle) > 0)
		dist_y = ((ceil(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	else
		dist_y = ((floor(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	//printf("dist_x = %f, dist_y = %f, sign: %d\n", dist_x, dist_y, sign(sin(pre_pos.angle)));
	if (dabs(dist_x) < dabs(dist_y))
	{
		//dist_x = dist_x * cos(pre_pos.angle) + pre_pos.x;
		if (cos(pre_pos.angle) > 0)
			dist_x = (floor(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE;	
		else
			dist_x = (ceil(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE;
		dist_y = (dist_x - pre_pos.x) * -1 * tan(pre_pos.angle) + pre_pos.y; 
	}
	else
	{
		//dist_y = dist_y * sin(pre_pos.angle) + pre_pos.y;
		if (sin(pre_pos.angle) > 0)
			dist_y = (ceil(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE;
		else
			dist_y = (floor(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE;
		dist_x = (dist_y - pre_pos.y) * -1 / tan(pre_pos.angle) + pre_pos.x;
	}
	result.angle = pre_pos.angle;
	result.x = dist_x;
	result.y = dist_y;
	return (result);
}

int	check_wall(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	(void)game;
	//printf("search: %d %d, max: %d %d\n", ((int)vec.y + 1) / CASE_SIZE, (int)vec.x / CASE_SIZE, map->height, map->width);
	//printf("search x: %f %.20f\n", vec.x - (int)vec.x, vec.x);
	//printf("search y: %f %f\n\n", vec.y - (int)vec.y, vec.y);
	if (vec.x - (int)vec.x == 0 && (int)vec.x % CASE_SIZE == 0)
	{
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x + 1)/ CASE_SIZE] == '1') 
			wall->face = 'W';
		if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x - 1)/ CASE_SIZE] == '1')
			wall->face = 'E';
		wall->dist_from_start = (int)vec.x - (int)vec.x / CASE_SIZE;
	}
	else
	{
		if (map->map[((int)vec.y + 1)/ CASE_SIZE][((int)vec.x) / CASE_SIZE] == '1') 
			wall->face = 'N';
		if (map->map[((int)vec.y - 1)/ CASE_SIZE][((int)vec.x) / CASE_SIZE] == '1')
			wall->face = 'S';
		wall->dist_from_start = (int)vec.y - (int)vec.y / CASE_SIZE;
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
		//printf("next: %f %f\n", next_inter.x, next_inter.y);
		is_wall = check_wall(game, &game->map, next_inter, wall);
	}
	wall->dist = sqrt(pow(ray.x - next_inter.x, 2) + pow(ray.y - next_inter.y, 2));
	return (0);
}

int	get_pixel_color(t_game *game, t_wall *wall, int y)
{
	if (y > WIN_HEIGHT - (tan(VIEW_SIZE) * wall->dist - WIN_HEIGHT * CASE_SIZE / (2 * 2 * wall->dist * tan(VIEW_SIZE))))
		return (game->map.c);
	else if (y < tan(VIEW_SIZE) * wall->dist - WIN_HEIGHT * CASE_SIZE / (2 * 2 * wall->dist * tan(VIEW_SIZE)))
		return (game->map.f);
	else
	{
		if (wall->face == 'N')
			return (0x00000000);
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

	//printf("i = %d\n", i);
	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_SCREEN / (double)WIN_WIDTH;
	ray.angle = atan (-d / game->settings.fov) + game->player.rot;
	ray.x = game->player.pos.x + d * sin(game->player.rot);
	ray.y = game->player.pos.y + d * cos(game->player.rot);
	//printf("ray angle: %f, ray x: %f, ray y: %f,  d: %f\n", ray.angle, ray.x, ray.y, d);
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

	i = 60;	
	while (++i < WIN_WIDTH)
		cast_ray(game, i);
	return (0);
}
