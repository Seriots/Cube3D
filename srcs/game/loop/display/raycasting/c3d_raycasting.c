/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 18:49:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "mlx.h"

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
		wall->dist_from_start = (int)vec.y % CASE_SIZE;
	}
	else
	{
		if (map->map[((int)vec.y + 1)/ CASE_SIZE][((int)vec.x) / CASE_SIZE] == '1') 
			wall->face = 'N';
		if (map->map[((int)vec.y - 1)/ CASE_SIZE][((int)vec.x) / CASE_SIZE] == '1')
			wall->face = 'S';
		wall->dist_from_start = (int)vec.x % CASE_SIZE;
	}
	//printf("dist: %d\n", wall->dist_from_start);
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

unsigned int	get_wall_color(t_game *game, t_wall *wall, int pixel, double d)
{
	void	*color;
	int	x;
	int	y;
	int min;
	int max;
	
	min = WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT / (wall->dist * 2 * VIEW_SIZE * cos(dabs(atan(d / game->settings.fov))));
	max = WIN_HEIGHT - min;
	x = (int)wall->dist_from_start * game->all_img.no.width / CASE_SIZE;
	y = (int)((pixel - min) * game->all_img.no.height / (max - min));
	//printf("x: %d, y: %d, min: %d, max: %d\n", x, y, min, max);
	if (wall->face == 'N')
		color = (game->all_img.no.addr + (y * game->all_img.no.line_length + x * (game->all_img.no.bits_per_pixel / 8)));
	else if (wall->face == 'S')
		color = (game->all_img.so.addr + (y * game->all_img.so.line_length + x * (game->all_img.so.bits_per_pixel / 8)));
	else if (wall->face == 'W')
		color = (game->all_img.we.addr + (y * game->all_img.we.line_length + x * (game->all_img.we.bits_per_pixel / 8)));
	else
		color = (game->all_img.ea.addr + (y * game->all_img.ea.line_length + x * (game->all_img.ea.bits_per_pixel / 8)));
	return (*(unsigned int *)(color));
}

int	get_pixel_color(t_game *game, t_wall *wall, int y, int i)
{
	double 		d;

	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_SCREEN / (double)WIN_WIDTH;
	//if (y < tan(VIEW_SIZE) * wall->dist - WIN_HEIGHT * CASE_SIZE / (2 * 2 * wall->dist * tan(VIEW_SIZE)))
	if ( y < WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT / (wall->dist * 2 * VIEW_SIZE * cos(dabs(atan(d / game->settings.fov)))))
		return (game->map.c);
	else if (WIN_HEIGHT - y < WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT / (wall->dist * 2 * VIEW_SIZE * cos(dabs(atan(d / game->settings.fov)))))
		return (game->map.f);
	else
	{
		/*if (wall->face == 'N')
			return (0x00000000);
		if (wall->face == 'S')
			return (0x00D300FF);
		if (wall->face == 'E')
			return (0x00D3FF00);
		return (0x00FFD300);
		*/
		return (get_wall_color(game, wall, y, d));
	}
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	int	j;
	int	color;

	j = 0;
	while (j < WIN_HEIGHT)
	{
		//printf ("y: %d, limit: %f\n", j, tan(VIEW_SIZE) * wall->dist - (double)(CASE_SIZE / 2));
		color = get_pixel_color(game, wall, j, i);
	
		my_mlx_pixel_put(&game->all_img.screen_img, i, j, color);
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

	i = -1;	
	while (++i < WIN_WIDTH)
		cast_ray(game, i);
	return (0);
}
