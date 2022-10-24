/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_textinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:14:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 19:15:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <stdlib.h>

static int	is_choose(t_game *game, t_textinput *box, int x, int y)
{
	if (x < box->box.x + 1 || x >= box->box.x + box->box.width - 1
		|| y < box->box.y + game->menu.scroll_amount + 1
		|| y >= box->box.y + game->menu.scroll_amount + box->box.height - 1)
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
	else if (box->is_selected)
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x686898);
	else
		my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x383838);
	return (0);
}

int	draw_textinput(t_game *game, t_textinput *box)
{
	int	x;
	int	y;

	y = box->box.y + game->menu.scroll_amount;
	while (y < box->box.y + game->menu.scroll_amount + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (y >= 0 && y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
				is_choose(game, box, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

static int	is_choose_start(t_game *game, t_textinput *box, int x, int y)
{
	if (x < box->box.x + 1 || x >= box->box.x + box->box.width - 1
		|| y < box->box.y + game->menu.scroll_amount + 1
		|| y >= box->box.y + game->menu.scroll_amount + box->box.height - 1)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
	else if (box->is_selected)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x686898);
	else
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x383838);
	return (0);
}

int	draw_textinput_start(t_game *game, t_textinput *box)
{
	int	x;
	int	y;

	y = box->box.y;
	while (y < box->box.y + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			is_choose_start(game, box, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
