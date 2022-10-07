/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_makemaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:31:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 11:22:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mzg_incs.h"

int	is_maze(char **map, int width, int height)
{
	int		i;
	int		j;
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
				fill(map, i, j, rand() % 90 + 35);
		}
	}
	return (0);
}

int	get_wall_destroy(t_wdestroy *w)
{
	int r;

	r = rand() % 4;
	w->y2 = w->y;
	w->x2 = w->x;
	if (r == 0)
		w->y2 = w->y + 2;
	else if (r == 1)
		w->y2 = w->y - 2;
	else if (r == 2)
		w->x2 = w->x + 2;
	else if (r == 3)
		w->x2 = w->x - 2;
	return (0);
}

int	make_maze(char **map, int width, int height)
{
	int			i;
	t_wdestroy	w;

	i = 0;
	set_random_value(map, width, height);
	while (!is_maze(map, width, height) && i++ < 100000)
	{
		w.x = (rand() % (width - 2)) + 1;
		w.y = (rand() % (height - 2)) + 1;
		if (map[w.y][w.x] > 33)
		{
			get_wall_destroy(&w);
			if (w.y2 > 0 && w.x2 > 0 && w.y2 < height - 1 && w.x2 < width - 1
				&& map[w.y2][w.x2] > 33 && map[w.y2][w.x2] != map[w.y][w.x])
			{
				map[abs((w.y + w.y2) / 2)][abs((w.x + w.x2) / 2)]
					= map[w.y][w.x];
				fill(map, w.x2, w.y2, map[w.y][w.x]);
				i = 0;
			}
		}		
	}
	return (0);
}
