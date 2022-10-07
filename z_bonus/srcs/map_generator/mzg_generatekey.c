/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generatekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:15:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 15:02:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

int	make_key(t_map *map, int width, int height, char c)
{
	int x;
	int y;

	x = rand() % width;
	y = rand() % height;
	while (map->map[y][x] != c)
	{
		x = rand() % width;
		y = rand() % height;
	}
	init_key(&map->all_objects, x, y);
	return (0);
}

int	generate_key(t_map *map, int width, int height, int door)
{
	int i;

	i = 0;
	while (i < door)
	{
		make_key(map, width, height, 'A' + i);
		i++;
	}
	return (0);
}