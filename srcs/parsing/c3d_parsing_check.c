/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:56:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/20 15:48:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_parsing.h"

#include "ft.h"

#include <stdio.h>

int	check_elements(t_map *map)
{
	if (!map->NO || !map->SO || !map->WE || !map->EA)
		return (6);
	if (map->F == -1 || map->C == -1)
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
			if (ft_isinset(map->map[i][j], "0NSWE") && check_around(map, i, j) != 0)
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

int	ft_complete(char *square_line, int width, char *line, char c)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		square_line[i] = line[i];
		i++;
	}
	while (i < width)
	{
		square_line[i] = c;
		i++;
	}
	return (0);
}

int	set_square_map(t_map *map)
{
	char	**square_map;
	int		i;

	square_map = ft_calloc(sizeof(char *), (map->height + 1));
	if (!square_map)
		return (10);
	i = 0;
	while (i < map->height)
	{
		square_map[i] = ft_calloc(sizeof(char), (map->width + 1));
		if (!square_map[i])
			return (ft_free_tab(square_map), 10);
		ft_complete(square_map[i], map->width, map->map[i], ' ');
		i++;
	}
	ft_free_tab(map->map);
	map->map = square_map;
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