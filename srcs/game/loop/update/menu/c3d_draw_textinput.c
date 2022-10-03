/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_textinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:14:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 15:15:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"

#include <stdlib.h>

int	draw_textinput(t_game *game, t_textinput *box)
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
