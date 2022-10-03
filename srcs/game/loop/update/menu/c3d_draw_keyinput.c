/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_keyinput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:06:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 12:45:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"

#include <stdlib.h>

int	draw_keyinput(t_game *game, t_keyinput *box)
{
	int	x;
	int	y;
	
	y = box->box.y;
	while (y < box->box.y + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (x < box->box.x + 1 || x >= box->box.x + box->box.width - 1
				|| y < box->box.y + 1 || y >= box->box.y + box->box.height - 1)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
			else if (box->is_selected)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x686898);
			else
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x383838);
			x++;
		}
		y++;
	}
	return (0);
}
