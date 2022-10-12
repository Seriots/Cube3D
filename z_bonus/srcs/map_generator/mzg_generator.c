/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:05:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 11:32:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#include "mlx.h"
#include "ft.h"

#include "mzg_incs.h"
#include "c3d_parsing.h"

/*
* Parmaeters:
* 1. map: a non allocated pointer of 2D array of chars
* 2. width: max width of the map
* 3. height: max height of the map
*
* Return value:
* 0: success
* 1: failure
* and the map is filled with the maze
*
* Description:
* This function generates a maze and fills the map with it.
* This generate a maze with the height as fixed value and with a variable width.
* you can use different fonction to clean the maze at the end.
* (no diago, no alone, only_alone) in the fill mzg_clean.c
*/

int	set_space(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			map[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (0);
}

int	init_map(t_map *map, int width, int height)
{
	int		i;

	map->map = ft_calloc(sizeof(char *), height + 1);
	if (!map->map)
		return (1);
	i = 0;
	while (i < height)
	{
		map->map[i] = ft_calloc(sizeof(char), width + 1);
		if (!map->map[i])
			return (ft_free_tab(map->map), 1);
		i++;
	}
	return (0);
}

int	set_default_image(t_map *map, int width, int height)
{
	map->no = ft_strdup(map->default_north);
	if (!map->no)
		return (10);
	map->so = ft_strdup(map->default_south);
	if (!map->so)
		return (10);
	map->we = ft_strdup(map->default_west);
	if (!map->we)
		return (10);
	map->ea = ft_strdup(map->default_east);
	if (!map->ea)
		return (10);
	map->f = ft_color(map->default_floor);
	if (map->f == -1)
		map->f = ft_color(DEFAULT_FLOOR);
	map->c = ft_color(map->default_ceil);
	if (map->c == -1)
		map->c = ft_color(DEFAULT_CEIL);
	map->width = width;
	map->height = height;
	return (0);
}

/*generate_player(map, width, height); //generate lampe in hard mode*/
int	gen_maze(t_game *game, int width, int height, int door)
{
	int		error;

	error = init_map(&game->map, width, height);
	if (error)
		return (1);
	set_space(game->map.map, width, height);
	makeshape_maze(game->map.map, width, height);
	fillmap(game->map.map);
	make_maze(game->map.map, width, height);
	standardize_maze_predoor(game->map.map, width, height);
	make_door(game->map.map, width, height, door);
	open_maze(game->map.map, width, height);
	clean_maze(game->map.map, width, height);
	generate_player(&game->map, width, height);
	generate_key(game, width, height, door);
	standardize_maze(game->map.map, width, height);
	error = set_default_image(&game->map, width, height);
	if (error)
		return (error);
	return (0);
}

int	get_maze(t_game *game, t_genparams params, unsigned long *seed, int print)
{
	int		error;

	if (params.seed == 0)
		params.seed = time(NULL);
	*seed = params.seed;
	srand(params.seed);
	error = gen_maze(game, params.width, params.height, params.door);
	if (error)
		return (error);
	if (print)
		printmaze(&game->map, params.width, params.height);
	return (0);
}
