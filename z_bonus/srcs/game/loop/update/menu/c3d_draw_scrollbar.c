/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_scrollbar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:34:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <stdlib.h>

int	draw_scrollbar(t_game *game, t_scrollbar *box)
{
	int	x;
	int	y;

	y = box->box.y;
	while (y < box->box.y + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (y >= 0 && y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
			{
				if (box->is_selected)
					my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x999999);
				else
					my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x383838);
			}
			x++;
		}
		y++;
	}
	return (0);
}
