/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_fillmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:30:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:17:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mzg_incs_bonus.h"

int	is_border(char **map, int x, int y)
{
	if (y == 0 || x == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (1);
	if (map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == ' '
		|| map[y][x - 1] == ' ' || map[y + 1][x + 1] == ' '
		|| map[y + 1][x - 1] == ' ' || map[y - 1][x + 1] == ' '
		|| map[y - 1][x - 1] == ' ')
		return (1);
	return (0);
}

int	enclosed_map(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] != ' ' && is_border(map, i, j))
			{
				map[j][i] = 33;
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	make_horizontal_walls(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j])
	{
		i = 0;
		if (j % 2 == 0)
		{
			while (map[j][i])
			{
				if (map[j][i] != ' ' && is_hor_ok(map, i, j))
					map[j][i] = 33;
				i++;
			}
		}
		j++;
	}
	return (0);
}

int	make_vertical_walls(char **map)
{
	int	i;
	int	j;

	j = 1;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (i % 2 == 0 && map[j][i] != ' ' && is_ver_ok(map, i, j))
				map[j][i] = 33;
			i++;
		}
		j++;
	}
	return (0);
}

int	fillmap(char **map)
{
	enclosed_map(map);
	make_horizontal_walls(map);
	make_vertical_walls(map);
	return (0);
}
