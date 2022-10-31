/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generate_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:17:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:40:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "mzg_incs.h"

#include "ft.h"

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
			&& map->map[y][x] != '0'
			&& map->map[y][x] != 'A'
			&& get_size_area(map->map, width, height, map->map[y][x]) > 10)
			break ;
	}
	c = map->map[y][x];
	map->map[y][x] = '-';
	return (c);
}

int	is_enclosed(t_map *map, int width, int height, t_point p)
{
	int	k;

	k = 0;
	if (p.x != 0 && map->map[p.y][p.x - 1] != '+')
		k++;
	if (p.x != width - 1 && map->map[p.y][p.x + 1] != '+')
		k++;
	if (p.y != 0 && map->map[p.y - 1][p.x] != '+')
		k++;
	if (p.y != height - 1 && map->map[p.y + 1][p.x] != '+')
		k++;
	return (k);
}

char	make_exit(t_map *map, int width, int height, char c)
{
	t_point	p;

	while (1)
	{
		p.x = rand() % width;
		p.y = rand() % height;
		if (map->map[p.y][p.x] != ' '
			&& map->map[p.y][p.x] != '+'
			&& map->map[p.y][p.x] != c
			&& map->map[p.y][p.x] != '0'
			&& map->map[p.y][p.x] != '-'
			&& is_enclosed(map, width, height, p) < 4)
			break ;
	}
	map->map[p.y][p.x] = '.';
	return (c);
}

int	generate_player(t_game *game, int width, int height)
{
	char	c;

	c = make_player(&game->map, width, height);
	make_key(game, width, height, c);
	make_exit(&game->map, width, height, c);
	return (0);
}
