/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_post_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:07:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 12:09:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	post_player(char **map, int width, int height)
{
	int	x;
	int	y;
	char	base[] = "NSEW";

	x = rand() % width;
	y = rand() % height;
	while (map[y][x] != '0')
	{
		x = rand() % width;
		y = rand() % height;
	}
	map[y][x] = base[rand() % 4];
	return (0);
}
