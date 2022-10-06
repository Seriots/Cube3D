/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_slidebar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:47:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_loop_bonus.h"

#include "mlx.h"

int	draw_bar(t_game *game, t_slidebar *slidebar)
{
	int	x;
	int	y;

	y = slidebar->y + game->menu.scroll_amount;
	while (y < slidebar->height + slidebar->y + game->menu.scroll_amount)
	{
		x = slidebar->x;
		while (x < slidebar->width + slidebar->x)
		{
			if (y >= 0 && y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
			{
				if (x > slidebar->box.x)
					my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xDDDDDD);
				else
					my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x686898);
			}
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

	y = slidebar->box.y + game->menu.scroll_amount;
	while (y < slidebar->box.y
		+ game->menu.scroll_amount + slidebar->box.height)
	{
		x = slidebar->box.x;
		while (x < slidebar->box.x + slidebar->box.width)
		{
			if (y >= 0 && y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x777777);
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