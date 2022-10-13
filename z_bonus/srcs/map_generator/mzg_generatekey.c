/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generatekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:15:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 11:32:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_object.h"

int	get_key_pos_force(t_game *game, int width, int height)
{
	int	x;
	int	y;
	int	i;

	x = rand() % width;
	y = rand() % height;
	i = 0;
	while (game->map.map[y][x] < 'A' && i < 500)
	{
		x = rand() % width;
		y = rand() % height;
		i++;
	}
	init_obj(game, KEY, x, y);
	return (0);
}

int	get_key_pos(t_game *game, int width, int height, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map.map[i][j] == c)
			{
				init_obj(game, KEY, j, i);
				return (1);
			}
			j++;
		}
		i++;
	}
	get_key_pos_force(game, width, height);
	return (0);
}

int	make_key(t_game *game, int width, int height, char c)
{
	int	x;
	int	y;
	int	i;

	x = rand() % width;
	y = rand() % height;
	i = 0;
	while (game->map.map[y][x] != c && i < 500)
	{
		x = rand() % width;
		y = rand() % height;
		i++;
	}
	if (i == 100)
		get_key_pos(game, width, height, c);
	else
		init_obj(game, KEY, x, y);
	return (0);
}

int	generate_key(t_game *game, int width, int height, int door)
{
	int	i;

	i = 0;
	while (i < door)
	{
		make_key(game, width, height, 'A' + i);
		i++;
	}
	return (0);
}
