/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:12:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 17:06:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "mzg_incs.h"
#include "c3d_init.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"

#include <stdlib.h>

#include <stdio.h>

int	load_random_map(t_game *game, t_genparams *params)
{
	if (game->settings.difficulty == 0)
		*params = (t_genparams){.width = 30, .height = 30, .door = 5,
			.seed = game->settings.seed, .difficulty = 0};
	else if (game->settings.difficulty == 1)
		*params = (t_genparams){.width = 50, .height = 50, .door = 12,
			.seed = game->settings.seed, .difficulty = 1};
	else
		*params = (t_genparams){.width = 80, .height = 80, .door = 20,
			.seed = game->settings.seed, .difficulty = 2};
	return (get_maze(game, *params, &game->settings.seed, 0));
}

int	set_door_coord(char face, t_point *p)
{
	p->x = 0;
	p->y = 0;
	if (face == 'N')
		p->y = -CASE_SIZE / 2;
	else if (face == 'S')
		p->y = CASE_SIZE / 2 - 1;
	else if (face == 'E')
		p->x = CASE_SIZE / 2 - 1;
	else if (face == 'W')
		p->x = -CASE_SIZE / 2;
	return (0);
}

int	init_one_door(t_game *game, t_map *map, int i, int j)
{
	char	face;
	int		error;
	t_point	coord;
	
	if (map->map[j - 1][i] == '0' && (map->map[j - 1][i + 1] == '0' || map->map[j - 1][i - 1] == '0'))
		face = 'N';
	else if (map->map[j + 1][i] == '0' && (map->map[j + 1][i + 1] == '0' || map->map[j + 1][i - 1] == '0'))
		face = 'S';
	else if (map->map[j][i - 1] == '0' && (map->map[j - 1][i - 1] == '0' || map->map[j + 1][i - 1] == '0'))
		face = 'W';
	else if (map->map[j][i + 1] == '0' && (map->map[j - 1][i + 1] == '0' || map->map[j + 1][i + 1] == '0'))
		face = 'E';
	else if (map->map[j - 1][i] == '0' || map->map[j + 1][i] == '0')
		face = 'N';
	else
		face = 'W';
	set_door_coord(face, &coord);
	error = init_obj(game, DOOR, i * CASE_SIZE + CASE_SIZE / 2 + coord.x,
		j * CASE_SIZE + CASE_SIZE / 2 + coord.y);
	if (error)
		return (error);
	find_door(game, i, j)->face = face;
	return (0);
}

int	get_all_doors(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	error;

	j = 0;
	error = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			if (map->map[j][i] == '2')
				error = init_one_door(game, map, i, j);
			if (map->map[j][i] == '3')
				error = init_obj(game, ENDOOR, i * CASE_SIZE + CASE_SIZE / 2,
						j * CASE_SIZE + CASE_SIZE / 2);
			if (error)
				return (error);
			i++;
		}
		j++;
	}
	return (0);
}

int	init_map_objects(t_game *game, t_map *map)
{
	int	error;

	(void)map;
	error = init_obj(game, LAMP, 0, 0);
	if (error)
		return (error);
	return (0);
}

double	get_light_value(int i, int j)
{
	double	dist_center;

	dist_center = sqrt(pow(i - WIN_WIDTH / 2, 2) + pow(j - WIN_HEIGHT / 2, 2));
	if (dist_center > 600)
		return (0.0);
	if (dist_center < 0)
		return (1);
	return (1 - (1 - 0.0) * sqrt((dist_center - 0) / (600)));
}

int	init_light(t_display *display)
{
	int	j;
	int	i;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			display->light_mask[j][i] = 80000 * pow(get_light_value(i, j), 2);
	}
	return (0);
}

int	init_display(t_display *display)
{
	int	i;

	i = -1;
	while (++i < WIN_WIDTH)
		display->doors[i].need_display = 0;
	init_light(display);
	return (0);
}

int	init_all_map_parameters(t_game *game, int first)
{
	int	error;

	error = get_all_doors(game, &game->map);
	if (error)
		return (error);
	error = init_map_objects(game, &game->map);
	if (error)
		return (error);
	error = init_player(game, &game->map, &game->player, first);
	if (error)
		return (error);
	error = open_textures(game, &game->map);
	if (error)
		return (error);
	init_display(&game->display);
	return (0);
}

int	load_new_map(t_game *game, char *map_path, int first)
{
	int			error;
	t_genparams	params;

	if (map_path)
	{
		error = parsing(game, &(game->map), map_path);
		if (error)
			return (free_map(&game->map), display_error(error));
	}
	else
	{
		error = load_random_map(game, &params);
		if (error)
			return (free_map(&game->map), display_error(error));
	}
	error = init_all_map_parameters(game, first);
	if (error)
		return (free_map(&game->map), display_error(error));
	game->map_start_frame = game->last_frame;
	load_default(game);
	return (0);
}
