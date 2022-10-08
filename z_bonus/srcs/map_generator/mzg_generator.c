/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:05:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 18:16:44 by lgiband          ###   ########.fr       */
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
	map->no = ft_strdup(DEFAULT_IMAGE_PATH_NO);
	if (!map->no)
		return (10);
	map->so = ft_strdup(DEFAULT_IMAGE_PATH_SO);
	if (!map->so)
		return (10);
	map->we = ft_strdup(DEFAULT_IMAGE_PATH_WE);
	if (!map->we)
		return (10);
	map->ea = ft_strdup(DEFAULT_IMAGE_PATH_EA);
	if (!map->ea)
		return (10);
	map->f = ft_color(DEFAULT_FLOOR);
	if (!map->f)
		return (10);
	map->c = ft_color(DEFAULT_CEIL);
	if (!map->c)
		return (10);
	map->width = width;
	map->height = height;
	return (0);
}

int	gen_maze(t_map *map, int width, int height, int door)
{
	int		error;

	error = init_map(map, width, height);
	if (error)
		return (1);
	set_space(map->map, width, height);
	makeshape_maze(map->map, width, height);
	fillmap(map->map);
	make_maze(map->map, width, height);
	standardize_maze_predoor(map->map, width, height);
	make_door(map->map, width, height, door);
	open_maze(map->map, width, height);
	clean_maze(map->map, width, height);
	generate_player(map, width, height); //generate lampe in hard mode
	generate_key(map, width, height, door);
	standardize_maze(map->map, width, height);
	error = set_default_image(map, width, height);
	if (error)
		return (ft_free_tab(map->map), error);
	return (0);
}

int	get_maze(t_map *map, int width, int height, int door)
{
	map->all_objects = NULL;
	srand(time(NULL) * getpid());
	gen_maze(map, width, height, door);
	//printmaze(map, width, height);
	return (0);
}