/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:17:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 15:49:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

#include "ft.h"

#include <stdio.h>

char	get_size_area(char **map, int width, int height, char c)
{
	int		i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == c)
				size ++;
			j++;
		}
		i++;
	}
	return (c);
}

char	make_player(t_map *map, int width, int height)
{
	int		x;
	int		y;
	char	c;

	while (1)
	{
		x = rand() % width;
		y = rand() % height;
		if (map->map[y][x] != ' '
			&& map->map[y][x] != '+'
			&& map->map[y][x] != '/'
			&& get_size_area(map->map, width, height, map->map[y][x]) > 10)
			break ;
	}
	c = map->map[y][x];
	map->map[y][x] = '-';
	return (c);
}

char	make_exit(t_map *map, int width, int height, char c)
{
	int	x;
	int	y;

	while (1)
	{
		x = rand() % width;
		y = rand() % height;
		if (map->map[y][x] != ' '
			&& map->map[y][x] != '+'
			&& map->map[y][x] != c
			&& map->map[y][x] != '-')
			break ;
	}
	map->map[y][x] = '.';
	return (c);
}

int	generate_player(t_map *map, int width, int height)
{
	char	c;

	c = make_player(map, width, height);
	make_exit(map, width, height, c);
	return (0);
}
