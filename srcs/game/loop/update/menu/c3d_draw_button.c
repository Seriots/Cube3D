/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:04:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_loop_bonus.h"

int	draw_button(t_game *game, t_button *box)
{
	int	x;
	int	y;

	y = box->box.y;
	while (y < box->box.y + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (x < box->box.x + BORDER_SIZE
				|| x > box->box.x + box->box.width - BORDER_SIZE
				|| y < box->box.y + BORDER_SIZE
				|| y > box->box.y + box->box.height - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
			else
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x111111);
			x++;
		}
		y++;
	}
	return (0);
}
