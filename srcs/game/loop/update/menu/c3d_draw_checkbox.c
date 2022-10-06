/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_checkbox.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:05:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_loop_bonus.h"
#include "c3d_utils_bonus.h"

#include <stdio.h>

static int	draw_in(t_game *game, t_checkbox *checkbox, int x, int y)
{
	if (checkbox->is_check && abs(x) - abs(y) < (checkbox->box.width / 15)
		&& abs(x) - abs(y) > - (checkbox->box.width / 15))
		my_mlx_pixel_put(&game->all_img.menu_img, x + checkbox->box.x,
			y + checkbox->box.y + game->menu.scroll_amount, 0xAAAAAA);
	else if (checkbox->is_check
		&& abs(x - checkbox->box.width) + abs(y - checkbox->box.height)
		> checkbox->box.width - (checkbox->box.width / 15)
		&& abs(x - checkbox->box.width) + abs(y - checkbox->box.height)
		< checkbox->box.width + (checkbox->box.width / 15))
		my_mlx_pixel_put(&game->all_img.menu_img, x + checkbox->box.x,
			y + checkbox->box.y + game->menu.scroll_amount, 0xAAAAAA);
	else
		my_mlx_pixel_put(&game->all_img.menu_img, x + checkbox->box.x,
			y + checkbox->box.y + game->menu.scroll_amount, 0x383838);
	return (0);
}

static int	is_border(t_game *game, t_checkbox *checkbox, int x, int y)
{
	if (x < checkbox->box.x + (checkbox->box.width / 15)
		|| x >= checkbox->box.x + checkbox->box.width
		- (checkbox->box.width / 15)
		|| y < checkbox->box.y + game->menu.scroll_amount
		+ (checkbox->box.width / 15)
		|| y >= checkbox->box.y + game->menu.scroll_amount
		+ checkbox->box.height - (checkbox->box.width / 15))
		return (1);
	return (0);
}

int	draw_checkbox(t_game *game, t_checkbox *checkbox)
{
	int	x;
	int	y;

	y = checkbox->box.y + game->menu.scroll_amount;
	while (y < checkbox->box.y
		+ game->menu.scroll_amount + checkbox->box.height)
	{
		x = checkbox->box.x;
		while (x < checkbox->box.x + checkbox->box.width)
		{
			if (y >= 0 && y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
			{
				if (is_border(game, checkbox, x, y))
					my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
				else
					draw_in(game, checkbox, x - checkbox->box.x,
						y - checkbox->box.y - game->menu.scroll_amount);
			}
			x++;
		}
		y++;
	}
	return (0);
}
