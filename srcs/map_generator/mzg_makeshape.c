/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_makeshape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:28:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:17:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mzg_incs_bonus.h"

#define VAR_FACTOR 800

int	gen_starting_shape(t_shape *shape, int width)
{
	shape->start = rand() % ((width / 2) - 2);
	shape->end = rand() % ((width / 2) - 2) + (width / 2) + 2 + (width % 2);
	shape->nb_end = 1;
	shape->nb_start = 1;
	return (0);
}

int	update_shape(t_shape *shape, int width)
{
	if (shape->nb_end > 2)
	{
		if (rand() % VAR_FACTOR < 10 * (shape->nb_end - 2))
		{
			shape->end = rand() % ((width / 2) - 2)
				+ (width / 2) + 2 + (width % 2);
			shape->nb_end = 0;
		}
	}
	if (shape->nb_start > 2)
	{
		if (rand() % VAR_FACTOR < 10 * (shape->nb_start - 2))
		{
			shape->start = rand() % ((width / 2) - 2);
			shape->nb_start = 0;
		}
	}
	shape->nb_end++;
	shape->nb_start++;
	return (0);
}

int	generate_line(t_shape *shape, char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (i < shape->start || i > shape->end)
			line[i] = 32;
		else
			line[i] = '0';
		i++;
	}
	return (0);
}

int	makeshape_maze(char **map, int width, int height)
{
	t_shape	shape;
	int		i;

	(void)height;
	(void)map;
	gen_starting_shape(&shape, width);
	i = 0;
	while (i < height)
	{
		generate_line(&shape, map[i], width);
		if (i > 5 && i < height - 5)
			update_shape(&shape, width);
		i++;
	}
	return (0);
}
