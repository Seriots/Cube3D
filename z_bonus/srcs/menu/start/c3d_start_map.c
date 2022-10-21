/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:12:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/21 15:33:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "mzg_incs.h"
#include "c3d_init.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"

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

int	get_all_doors(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == '2')
				error = init_obj(game, DOOR, j * CASE_SIZE + CASE_SIZE / 2,
						i * CASE_SIZE + CASE_SIZE / 2);
			if (map->map[i][j] == '3')
				error = init_obj(game, ENDOOR, j * CASE_SIZE + CASE_SIZE / 2,
						i * CASE_SIZE + CASE_SIZE / 2);
			if (error)
				return (error);
			j++;
		}
		i++;
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
