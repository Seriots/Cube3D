/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 10:36:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	default_display(t_game *game)
{
	mlx_clear_window(game->mlx.display, game->mlx.window);
	for (int k = 0; k < 50; k++)
	{
		for (int l = 0; l < 50; l++)
			mlx_pixel_put(game->mlx.display, game->mlx.window,
					game->player.pos.x + l, game->player.pos.y + k, COLOR);
	}
	usleep(10000);
	return (0);
}