/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_openmaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:19:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 14:14:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft.h"

#include <stdio.h>

int	count_wall(char **map, int width, int height)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == '+')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_door(char **map, int x, int y)
{
	if (map[y + 1][x] == '/' || map[y + 1][x] == ' ')
		return (1);
	if (map[y][x + 1] == '/' || map[y][x + 1] == ' ')
		return (1);
	if (map[y - 1][x] == '/' || map[y - 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == '/' || map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	is_aligned(char **map, int x, int y)
{
	if ((map[y - 1][x] == map[y + 1][x] && map[y - 1][x] != '+')
		|| (map[y][x - 1] == map[y][x + 1] && map[y][x - 1] != '+'))
		return (1);
	return (0);
}

char	is_between_room(char **map, int x, int y)
{
	char	tab[127];
	int		i;
	char	c;

	ft_bzero(tab, 127 * sizeof(char));
	if (map[y + 1][x] != '+')
		tab[(int)map[y + 1][x]] = 1;
	if (map[y][x + 1] != '+')
		tab[(int)map[y][x + 1]] = 1;
	if (map[y - 1][x] != '+')
		tab[(int)map[y - 1][x]] = 1;
	if (map[y][x - 1] != '+')
		tab[(int)map[y][x - 1]] = 1;
	c = 0;
	i = -1;
	while (++i < 127)
	{
		if (tab[i] == 1)
		{
			if (c != 0)
				return (0);
			c = i;
		}
	}
	return (c);
}

char	is_destroyable(char **map, int x, int y)
{
	int		count;
	char	c;

	count = 0;
	if (is_door(map, x, y))
		return (0);
	if (!is_aligned(map, x, y))
		return (0);
	c = is_between_room(map, x, y);
	return (c);
}

int open_maze(char **map, int width, int height)
{
	int	nb_wall;
	int	i;
	int	j;
	int	x;
	int	y;
	char c;

	nb_wall = count_wall(map, width, height);
	i = 0;
	j = 0;
	while (i < nb_wall / 4 && j < 200)
	{
		x = 1 + rand() % (width - 2);
		y = 1 + rand() % (height - 2);
		if (map[y][x] == '+')
		{
			c = is_destroyable(map, x, y);
			if (c)
			{
				map[y][x] = c;
				i++;
				j = 0;
			}
		}
		j++;
	}
	return (0);	
}