/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_makemaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:31:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 12:14:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mzg_incs.h"

int	is_maze(char **map, int width, int height)
{
	int	i;
	int	j;
	char	c;

	c = 0;
	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			if (c == 0 && map[j][i] > 33)
				c = map[j][i];
			else if (c != 0 && map[j][i] > 33 && map[j][i] != c)
				return (0);
		}
	}
	return (1);
}

int	abs(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

int	fill(char **map, int x, int y, char c)
{
	map[y][x] = c;
	if (map[y][x - 1] != c && map[y][x - 1] != 33)
		fill(map, x - 1, y, c);
	if (map[y][x + 1] != c && map[y][x + 1] != 33)
		fill(map, x + 1, y, c);
	if (map[y - 1][x] != c && map[y - 1][x] != 33)
		fill(map, x, y - 1, c);
	if (map[y + 1][x] != c && map[y + 1][x] != 33)
		fill(map, x, y + 1, c);
	return (0);
}

int	set_random_value(char **map, int width, int height)
{
	int	i;
	int	j;

	j = -1;
	while (++j < height)
	{
		i = -1;
		while (++i < width)
		{
			if (map[j][i] == '0')
				fill(map, i, j, rand() % 90 + 34);
		}
	}
	return (0);
}

int	make_maze(char **map, int width, int height)
{
	int	i;
	int	x;
	int	y;
	int	x2;
	int	y2;
	//int	r;
	
	i = 0;
	set_random_value(map, width, height);
	while (!is_maze(map, width, height) && i < 1000)
	{
		x = (rand() % (width - 2)) + 1;	 	
		y = (rand() % (height - 2)) + 1;	 	
		if (map[y][x] > 33)
		{
			/*r = rand() % 4;
			y2 = y;
			x2 = x;
			if (r == 0)
				y2 = y + 2;
			else if (r == 1)
				y2 = y - 2;
			else if (r == 2)
				x2 = x + 2;
			else if (r == 3)
				x2 = x - 2;*/
			y2 = y + (2 * (rand() % 3 - 1));
			x2 = x + (2 * (rand() % 3 - 1));
			if (y2 > 0 && x2 > 0 && y2 < height - 1 && x2 < width - 1 && map[y2][x2] > 33 && map[y2][x2] != map[y][x])
			{
				map[abs((y + y2) / 2)][abs((x + x2) / 2)] = map[y][x];
				fill(map, x2, y2, map[y][x]);
				i = 0;
			}
			else
				i++;
		}		
	}
	return (0);
}
