/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 16:16:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "mlx.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_put_image_to_window(t_game *game, t_img_data *data, int x, int y)
{
	char	*dst;
	int		i;
	int		j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			dst = data->addr + (j * data->line_length
					+ i * (data->bits_per_pixel / 8));
			if (*(unsigned int *)dst != 0xFF000000)
				my_mlx_pixel_put(&game->all_img.screen_img, x + i, y + j,
					*(unsigned int *)dst);
			i++;
		}
		j++;
	}
}

int	default_display(t_game *game)
{
	raycasting(game);
	my_mlx_put_image_to_window(game, &game->all_img.minimap_img, 10, 500);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	return (0);
}
