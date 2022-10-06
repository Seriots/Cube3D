/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:56:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_parsing.h"

#include "ft.h"

#include <stdio.h>

int	check_elements(t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea)
		return (6);
	if (map->f == -1 || map->c == -1)
		return (6);
	if (!map->map)
		return (7);
	return (0);
}

int	check_around(t_map *map, int i, int j)
{
	if (i <= 0 || j <= 0 || i >= map->height - 1 || j >= map->width - 1)
		return (1);
	else if (map->map[i - 1][j] == ' ')
		return (1);
	else if (map->map[i + 1][j] == ' ')
		return (1);
	else if (map->map[i][j - 1] == ' ')
		return (1);
	else if (map->map[i][j + 1] == ' ')
		return (1);
	else if (map->map[i + 1][j + 1] == ' ')
		return (1);
	else if (map->map[i - 1][j - 1] == ' ')
		return (1);
	else if (map->map[i + 1][j - 1] == ' ')
		return (1);
	else if (map->map[i - 1][j + 1] == ' ')
		return (1);
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_isinset(map->map[i][j], "0NSWE")
				&& check_around(map, i, j) != 0)
				return (9);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_players(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (8);
	return (0);
}

int	check_map(t_map *map)
{
	int	error;

	error = check_elements(map);
	if (error)
		return (error);
	error = set_square_map(map);
	if (error)
		return (error);
	error = check_players(map);
	if (error)
		return (error);
	error = check_walls(map);
	if (error)
		return (error);
	return (0);
}
