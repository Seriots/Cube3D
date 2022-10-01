/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_slidebar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:47:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 21:06:52 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"

#include "mlx.h"

int	draw_bar(t_game *game, t_slidebar *slidebar)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < slidebar->height)
	{
		x = 0;
		while (x < slidebar->width)
		{
			if (x + slidebar->x > slidebar->box.x)
				my_mlx_pixel_put(&game->all_img.menu_img, x + slidebar->x, y + slidebar->y, 0xFFDDDD);
			else
				my_mlx_pixel_put(&game->all_img.menu_img, x + slidebar->x, y + slidebar->y, 0xAA8888);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_slider(t_game *game, t_slidebar *slidebar)
{
	int	x;
	int	y;

	y = 0;
	while (y < slidebar->box.height)
	{
		x = 0;
		while (x < slidebar->box.width)
		{
			my_mlx_pixel_put(&game->all_img.menu_img, x + slidebar->box.x, y + slidebar->box.y, 0x777777);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_slidebar(t_game *game, t_slidebar *slidebar)
{
	draw_bar(game, slidebar);
	draw_slider(game, slidebar);
	return (0);
}
