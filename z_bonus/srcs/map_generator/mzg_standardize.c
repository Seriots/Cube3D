/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_standardize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:33:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 14:37:46 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mzg_incs.h"

int	standardize_maze(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == '+')
				map[j][i] = '1';
			else if (map[j][i] == '/')
				map[j][i] = '2';
			else if (map[j][i] == '-')
				map[j][i] = BASE[rand() % 4];
			else if (map[j][i] == '.')
				map[j][i] = '3';
			else if (map[j][i] != 32)
				map[j][i] = '0';
			i++;
		}
		j++;
	}
	return (0);
}

int	standardize_maze_predoor(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == 33)
				map[j][i] = '+';
			else if (map[j][i] != 32)
				map[j][i] = 'A';
			i++;
		}
		j++;
	}
	return (0);
}
