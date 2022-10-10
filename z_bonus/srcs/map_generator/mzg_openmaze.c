/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_openmaze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:19:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 14:25:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mzg_incs.h"
#include "c3d_struct.h"

#include "ft.h"

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

int	open_maze(char **map, int width, int height)
{
	t_point	p;
	int		nb_wall;
	int		i;
	int		j;
	char	c;

	nb_wall = count_wall(map, width, height);
	i = 0;
	j = 0;
	while (i < nb_wall / OPEN_FACTOR && ++j < 200)
	{
		p.x = 1 + rand() % (width - 2);
		p.y = 1 + rand() % (height - 2);
		if (map[p.y][p.x] == '+')
		{
			c = is_destroyable(map, p.x, p.y);
			if (c)
			{
				map[p.y][p.x] = c;
				i++;
				j = 0;
			}
		}
	}
	return (0);
}
