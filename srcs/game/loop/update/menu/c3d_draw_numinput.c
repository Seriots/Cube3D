/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_numinput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:37:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_loop_bonus.h"

#include <stdlib.h>

static int	is_choose(t_game *game, t_numbox numbox, t_numinput *box, t_point p)
{
	if (p.x < numbox.x + 1 || p.x >= numbox.x + numbox.width - 1
		|| p.y < numbox.y + game->menu.scroll_amount + 1
		|| p.y >= numbox.y + numbox.height + game->menu.scroll_amount - 1)
		my_mlx_pixel_put(&game->all_img.menu_img, p.x, p.y, 0xAAAAAA);
	else if (box->is_selected == numbox.value)
		my_mlx_pixel_put(&game->all_img.menu_img, p.x, p.y, 0x686898);
	else
		my_mlx_pixel_put(&game->all_img.menu_img, p.x, p.y, 0x383838);
	return (0);
}

int	draw_square(t_game *game, t_numbox numbox, t_numinput *box)
{
	t_point	p;

	p.y = numbox.y + game->menu.scroll_amount;
	while (p.y < numbox.y + numbox.height + game->menu.scroll_amount)
	{
		p.x = numbox.x;
		while (p.x < numbox.x + numbox.width)
		{
			if (p.y >= 0 && p.y < MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
				is_choose(game, numbox, box, p);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int	draw_numinput(t_game *game, t_numinput *box)
{
	t_numbox	numbox;

	numbox.x = box->box.x;
	numbox.y = box->box.y;
	numbox.width = box->box.width / 4;
	numbox.height = box->box.height;
	numbox.value = 1;
	draw_square(game, numbox, box);
	numbox.x = box->box.x + (3 * numbox.width / 2);
	numbox.value = 2;
	draw_square(game, numbox, box);
	numbox.x = box->box.x + numbox.width * 3;
	numbox.value = 3;
	draw_square(game, numbox, box);
	return (0);
}
