/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_minimap_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:41:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 17:34:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include <stdio.h>

/*
unsigned int	get_image_color(t_img_data *img, int x, int y)
{
	unsigned int	color;
	
	color = *(unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
	return (color);
}

void drawRotateSprite(t_game* game, int x, int y)
{
	t_img_data	*img;
	int			cx;
	int			cy;

	img = &game->all_img.all_cursor_img[0];	
	cx = (img->width / 2);
	cy = (img->height / 2);
    for (int dy = 0; dy < img->height; dy++)
    {
        for (int dx = 0; dx < img->width; dx++)
        {
            float ex = cos(-game->player.plane.value) * (dx - cx) + sin(-game->player.plane.value) * (dy - cy);
            float ey = -sin(-game->player.plane.value) * (dx - cx) + cos(-game->player.plane.value) * (dy - cy);

			ex += cx;
			ey += cy;
			unsigned int color = get_image_color(img, ex, ey);
			if (color == 0xCB1212)
            	my_mlx_pixel_put(&game->all_img.minimap_img, x - cx + dx, y - cy + dy, get_image_color(img, ex, ey));
        }
    }
}*/

int	get_cursor_image(t_game *game)
{
	return ((int)((game->player.plane.value + (M_PI / 8))
		/ (2 * M_PI) * 8) % 8);
}

void	*get_player_color(t_game *game, int i, int j)
{
	return (game->all_img.all_cursor_img[get_cursor_image(game)].addr
		+ (j * game->all_img.all_cursor_img[get_cursor_image(game)].line_length)
		+ (i * (game->all_img.all_cursor_img
				[get_cursor_image(game)].bits_per_pixel / 8)));
}

unsigned int	get_map_color(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0x000000);
	else if (game->map.map[y][x] == '1')
		return (0x398AE6);
	else if (game->map.map[y][x] == '2')
		return (0xF11616);
	else if (game->map.map[y][x] == '3')
		return (0x07E529);
	else if (game->map.map[y][x] == ' ')
		return (0x000000);
	else
		return (0x00ACCFF7);
}

int	put_player(t_game *game)
{
	int		i;
	int		j;
	void	*color;

	i = 0;
	while (i < MMAP_CASE_SIZE - 1)
	{
		j = 0;
		while (j < MMAP_CASE_SIZE - 1)
		{
			color = get_player_color(game, i, j);
			if (*(unsigned int *)color != 0xFF000000)
				my_mlx_pixel_put(&game->all_img.minimap_img,
					(MMAP_WIDTH / 2) - (MMAP_CASE_SIZE / 2) + i,
					(MMAP_HEIGHT / 2) - (MMAP_CASE_SIZE / 2) + j,
					*(unsigned int *)color);
			j++;
		}
		i++;
	}
	return (0);
}

int	update_minimap(t_game *game)
{
	unsigned int		color;
	int					i;
	int					j;
	int					x;
	int					y;

	i = 0;
	while (i < MMAP_HEIGHT)
	{
		j = 0;
		while (j < MMAP_WIDTH)
		{
			x = floor(((game->player.pos.x * MMAP_CASE_SIZE / CASE_SIZE)
						+ j - MMAP_WIDTH / 2) / MMAP_CASE_SIZE);
			y = floor(((game->player.pos.y * MMAP_CASE_SIZE / CASE_SIZE)
						+ i - MMAP_HEIGHT / 2) / MMAP_CASE_SIZE);
			color = get_map_color(game, x, y);
			color = is_in_circle(j, i, color);
			my_mlx_pixel_put(&game->all_img.minimap_img, j, i, color);
			j++;
		}
		i++;
	}
	put_player(game);
	//drawRotateSprite(game, MMAP_WIDTH / 2, MMAP_HEIGHT / 2);
	return (0);
}
