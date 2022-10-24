/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_nameinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:15:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 19:26:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

static int	is_choose_end(t_game *game, t_nameinput *box, int x, int y)
{
	if (x < box->box.x + 1 || x >= box->box.x + box->box.width - 1
		|| y < box->box.y + game->end_menu.scroll_amount + 1
		|| y >= box->box.y + game->end_menu.scroll_amount + box->box.height - 1)
		my_mlx_pixel_put(&game->all_img.end_img, x, y, 0xAAAAAA);
	else if (box->is_selected)
		my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x686898);
	else
		my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x383838);
	return (0);
}

int	draw_nameinput(t_game *game, t_nameinput *box)
{
	int	x;
	int	y;

	y = box->box.y + game->end_menu.scroll_amount;
	while (y < box->box.y + game->end_menu.scroll_amount + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (y >= (15 * MENU_HEIGHT / 100)
				&& y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
				is_choose_end(game, box, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
