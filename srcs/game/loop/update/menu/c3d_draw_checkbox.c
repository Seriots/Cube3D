/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_checkbox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:05:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 12:15:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include <stdio.h>

static int	draw_in(t_game *game, t_checkbox *checkbox, int x, int y)
{
	if (checkbox->is_check && abs(x) - abs(y) < (checkbox->box.width / 10) && abs(x) - abs(y) > -(checkbox->box.width / 10))
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x888888);
	else if (checkbox->is_check
			&& abs(x - checkbox->box.x) + abs(y - checkbox->box.y) > checkbox->box.width - (checkbox->box.width / 10) 
			&& abs(x - checkbox->box.x) + abs(y - checkbox->box.y) < checkbox->box.width + (checkbox->box.width / 10))
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x888888);
	else
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xFFDDDD);
	return (0);
}

int	draw_checkbox(t_game *game, t_checkbox *checkbox)
{
	int	x;
	int	y;
	
	y = checkbox->box.y;
	while (y < checkbox->box.y + checkbox->box.height)
	{
		x = checkbox->box.x;
		while (x < checkbox->box.x + checkbox->box.width)
		{
			if (x < checkbox->box.x + (checkbox->box.width / 10) || x >= checkbox->box.x + checkbox->box.width - (checkbox->box.width / 10)
				|| y < checkbox->box.y + (checkbox->box.width / 10) || y >= checkbox->box.y + checkbox->box.height - (checkbox->box.width / 10))
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x777777);
			else
				draw_in(game, checkbox, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
