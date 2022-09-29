/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:41:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 16:38:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

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

int	put_facing(t_game *game)
{
	int i;
	int j;
	int	k;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			k = 0;
			while (k < 8)
			{
				my_mlx_pixel_put(&game->all_img.minimap_img,
					(MMAP_WIDTH / 2) + k * cos(game->player.rot + 0.1 * sign(game->player.rot - M_PI)) + j,
					(MMAP_HEIGHT / 2) + k * -sin(game->player.rot + 0.1 * sign(game->player.rot - M_PI)) + i, 0xBB0000);
				
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_cursor_image(t_game *game)
{
	return ((int)((game->player.rot + (M_PI / 8)) / (2 * M_PI) * 8) % 8);
}

int	put_player(t_game *game)
{
	int	i;
	int	j;
	void	*color;

	i = 0;
	while (i < MMAP_CASE_SIZE - 1)
	{
		j = 0;
		while (j < MMAP_CASE_SIZE - 1)
		{
			color = (game->all_img.all_cursor_img[get_cursor_image(game)].addr
				+ (j * game->all_img.all_cursor_img[get_cursor_image(game)].line_length)
				+ (i * (game->all_img.all_cursor_img[get_cursor_image(game)].bits_per_pixel / 8)));
			if (*(unsigned int *)color != 4278190080)
				my_mlx_pixel_put(&game->all_img.minimap_img,
					(MMAP_WIDTH / 2) - (MMAP_CASE_SIZE / 2) + i,
					(MMAP_HEIGHT / 2) - (MMAP_CASE_SIZE / 2) + j, *(unsigned int *)color);
			j++;
		}
		i++;
	}
	//put_facing(game);
	
	return (0);
}
/*
int	update_minimap(t_game *game)
{
	int	i;
	int	j;
	int	case_x;
	int	case_y;
	int	color;

	i = 0;
	color = 0;
	//probleme au decalage d'une case pile genre player en 640
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
			
			put_one_case(game,
					j * MMAP_CASE_SIZE - (((int)(game->player.pos.x) % CASE_SIZE) * MMAP_CASE_SIZE / CASE_SIZE),
					i * MMAP_CASE_SIZE - (((int)(game->player.pos.y) % CASE_SIZE) * MMAP_CASE_SIZE / CASE_SIZE),
					color);
			j++;
		}
		i++;
	}
	
	
	put_player(game);
	return (0);
}*/

int	update_minimap(t_game *game)
{
	int		i;
	int		j;
	int		color;
	int		x;
	int		y;

	i = 0;
	while (i < MMAP_HEIGHT)
	{
		j = 0;
		while (j < MMAP_WIDTH)
		{
			//if ((i == 76 && j == 76) || (i == 94 && j == 94))
			//	printf("i = %d, j = %d, playerx: %f, playery: %f\n", i, j, game->player.pos.x * 10 / 64, game->player.pos.y * 10 / 64);
			x = floor(((game->player.pos.x * 10.0 / 64.0) + j - 200/2) / 10);
			y = floor(((game->player.pos.y * 10.0 / 64.0) + i - 200/2) / 10);
			//if ((i == 76 && j == 76) || (i == 94 && j == 94))
			//	printf("x = %d, y = %d\n", x, y);
			if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
				color = 0x000000;
			else if (game->map.map[y][x] == '1')
				color = 0x398AE6;
			else if (game->map.map[y][x] == ' ')
				color = 0x000000;
			else
				color = 0x00ACCFF7;
			my_mlx_pixel_put(&game->all_img.minimap_img, j, i, color);
			j++;
		}
		i++;
	}
	
	put_player(game);
	return (0);
}
