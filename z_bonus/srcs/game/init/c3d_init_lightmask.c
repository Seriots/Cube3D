/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_lightmask.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:07:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 11:40:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

#include "stdio.h"

#include <stdlib.h>

double	get_mask_value(t_game *game, int x, int y)
{
	(void)game;
	double	dist;

	dist = pow(x - WIN_WIDTH / 2, 2) + pow(y - WIN_HEIGHT / 2, 2);
	if (dist < 60000)
		return (1.0);
	else if (dist < 80000)
		return (0.9);
	else if (dist < 90000)
		return (0.8);
	else if (dist < 100000)
		return (0.7);
	else if (dist < 105000)
		return (0.6);
	else if (dist < 107500)
		return (0.5);
	else if (dist < 108750)
		return (0.4);
	return (0.2);
}

int	set_lightmask(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			game->lightmask[y][x] = get_mask_value(game, x, y);
			x++;
		}
		y++;
	}
	
	return (0);
}

int	init_lightmask(t_game *game)
{
	int		i;

	game->lightmask = ft_calloc(sizeof(double *), WIN_HEIGHT);
	if (!game->lightmask)
		return (10);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		game->lightmask[i] = ft_calloc(sizeof(double), WIN_WIDTH);
		if (!game->lightmask[i])
			return (10);
		i++;
	}
	set_lightmask(game);
	return (0);
}