/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_seed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:49:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 16:01:23 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

static int	is_choose(t_game *game, t_seed *box, int x, int y)
{
	if (x < box->box.x + 1
		|| x >= box->box.x + box->box.width - 1
		|| y < box->box.y + 1
		|| y >= box->box.y + box->box.height - 1)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
	else if (box->is_selected)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x686898);
	else
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x383838);
	return (0);
}

int	draw_seed(t_game *game, t_seed *box)
{
	int	x;
	int	y;

	y = box->box.y;
	while (y < box->box.y + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			is_choose(game, box, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
