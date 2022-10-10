/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generatekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:15:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 15:31:33 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

int	get_key_pos_force(t_map *map, int width, int height)
{
	int	x;
	int	y;
	int	i;

	x = rand() % width;
	y = rand() % height;
	i = 0;
	while (map->map[y][x] < 'A' && i < 500)
	{
		x = rand() % width;
		y = rand() % height;
		i++;
	}
	init_key(&map->all_objects, x, y);
	return (0);
}

int	get_key_pos(t_map *map, int width, int height, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map->map[i][j] == c)
			{
				init_key(&map->all_objects, j, i);
				return (1);
			}
			j++;
		}
		i++;
	}
	get_key_pos_force(map, width, height);
	return (0);
}

int	make_key(t_map *map, int width, int height, char c)
{
	int	x;
	int	y;
	int	i;

	x = rand() % width;
	y = rand() % height;
	i = 0;
	while (map->map[y][x] != c && i < 500)
	{
		x = rand() % width;
		y = rand() % height;
		i++;
	}
	if (i == 100)
		get_key_pos(map, width, height, c);
	else
		init_key(&map->all_objects, x, y);
	return (0);
}

int	generate_key(t_map *map, int width, int height, int door)
{
	int	i;

	i = 0;
	while (i < door)
	{
		make_key(map, width, height, 'A' + i);
		i++;
	}
	return (0);
}
