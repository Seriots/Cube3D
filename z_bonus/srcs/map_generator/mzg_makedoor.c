/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_makedoor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:12:38 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 14:02:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft.h"

#include <stdio.h>

int	is_doorable(char **map, int x, int y)
{
	if (ft_isinset(map[y][x], " +/"))
		return (0);
	if (map[y][x - 1] == '+' && map[y][x + 1] == '+'
		&& map[y - 1][x] == map[y + 1][x])
		return (1);
	if (map[y - 1][x] == '+' && map[y + 1][x] == '+'
		&& map[y][x - 1] == map[y][x + 1])
		return (2);
	return (0);
}

int	floud_fill(char **map, int x, int y, char c)
{
	if (map[y][x] >= 'A' && map[y][x] != c)
	{
		map[y][x] = c;
		floud_fill(map, x + 1, y, c);
		floud_fill(map, x - 1, y, c);
		floud_fill(map, x, y + 1, c);
		floud_fill(map, x, y - 1, c);
	}
	return (0);
}

int	generate_door(char **map, int width, int height, char newroom)
{
	int	x;
	int	y;
	int	door;

	while (1)
	{
		x = 1 + rand() % (width - 2);
		y = 1 + rand() % (height - 2);
		door = is_doorable(map, x, y);
		if (door)
			break ;
	}
	map[y][x] = '/';
	if (door == 1)
		floud_fill(map, x, y + 1, newroom);
	else
		floud_fill(map, x + 1, y, newroom);
	return (0);
}

int	make_door(char **map, int width, int height, int door)
{
	int	i;	

	i = 0;
	while (i < door)
	{
		generate_door(map, width, height, 'A' + i);
		i++;
	}
	return (0);
}
