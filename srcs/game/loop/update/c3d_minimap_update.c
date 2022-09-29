/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:41:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 11:18:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <stdio.h>

int	put_one_case(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MMAP_CASE_SIZE)
	{
		j = 0;
		while (j < MMAP_CASE_SIZE)
		{
			if (x + i < MMAP_WIDTH && y + j < MMAP_HEIGHT
				&& x + i >= 0 && y + j >= 0)
				my_mlx_pixel_put(&game->all_img.minimap_img,
					x + i, y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}

int	put_player(t_game *game)
{
	int	i;
	int	j;

	i = 2;
	while (i < MMAP_CASE_SIZE - 2)
	{
		j = 2;
		while (j < MMAP_CASE_SIZE - 2)
		{
			my_mlx_pixel_put(&game->all_img.minimap_img,
				(MMAP_WIDTH / 2) - (MMAP_CASE_SIZE / 2) + i,
				(MMAP_HEIGHT / 2) - (MMAP_CASE_SIZE / 2) + j, 0xFF0000);
			j++;
		}
		i++;
	}
	return (0);
}

int	update_minimap(t_game *game)
{
	int	i;
	int	j;
	int	case_x;
	int	case_y;
	int	color;

	i = 0;
	color = 0;
	case_x = ((game->player.pos.x)
			- (CASE_SIZE * (MMAP_WIDTH / MMAP_CASE_SIZE) / 2));
	case_y = ((game->player.pos.y)
			- (CASE_SIZE * (MMAP_HEIGHT / MMAP_CASE_SIZE) / 2));
	while (i < MMAP_HEIGHT / MMAP_CASE_SIZE + 1)
	{
		j = 0;
		while (j < MMAP_WIDTH / MMAP_CASE_SIZE + 1)
		{
			if ((case_y / CASE_SIZE) + i < 0 || (case_x / CASE_SIZE) + j < 0)
				color = 0x000000;
			else if ((case_y / CASE_SIZE) + i >= game->map.height
				|| (case_x / CASE_SIZE) + j >= game->map.width)
				color = 0x000000;
			else if (game->map.map[(case_y / CASE_SIZE) + i]
				[(case_x / CASE_SIZE) + j] == '1')
				color = 0x398AE6;
			else if (game->map.map[(case_y / CASE_SIZE) + i]
				[(case_x / CASE_SIZE) + j] == ' ')
				color = 0x000000;
			else
				color = 0x00ACCFF7;
			put_one_case(game, j * MMAP_CASE_SIZE - (((int)game->player.pos.x % CASE_SIZE) * MMAP_CASE_SIZE / CASE_SIZE), i * MMAP_CASE_SIZE - (((int)game->player.pos.y % CASE_SIZE) * MMAP_CASE_SIZE / CASE_SIZE), color);
			j++;
		}
		i++;
	}
	put_player(game);
	return (0);
}
