/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generatekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:15:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 14:02:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_object.h"

#include <stdio.h>

int	get_key_pos_force(t_game *game, int width, int height)
{
	int	x;
	int	y;
	int	i;
	int	error;

	x = rand() % width;
	y = rand() % height;
	i = 0;
	while (game->map.map[y][x] < 'A' && i < 500)
	{
		x = rand() % width;
		y = rand() % height;
		i++;
	}
	error = init_obj(game, KEY,
			x * CASE_SIZE + 16 + (rand() % 32),
			y * CASE_SIZE + 16 + (rand() % 32));
	return (error);
}

int	get_key_pos(t_game *game, int width, int height, char c)
{
	int	i;
	int	j;
	int	error;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map.map[i][j] == c)
			{
				error = init_obj(game, KEY,
						j * CASE_SIZE + 16 + (rand() % 32),
						i * CASE_SIZE + 16 + (rand() % 32));
				return (error);
			}
			j++;
		}
		i++;
	}
	error = get_key_pos_force(game, width, height);
	return (error);
}

int	make_key(t_game *game, int width, int height, char c)
{
	int	x;
	int	y;
	int	i;
	int	error;

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
		error = get_key_pos(game, width, height, c);
	else
		error = init_obj(game, KEY,
				x * CASE_SIZE + 16 + (rand() % 32),
				y * CASE_SIZE + 16 + (rand() % 32));
	return (error);
}

int	generate_key(t_game *game, int width, int height, int door)
{
	int	i;
	int	error;

	i = 0;
	while (i < door)
	{
		error = make_key(game, width, height, 'A' + i);
		if (error)
			return (error);
		i++;
	}
	return (0);
}
