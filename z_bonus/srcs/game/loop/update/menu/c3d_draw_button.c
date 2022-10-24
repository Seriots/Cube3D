/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:04:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 20:07:16 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

int	draw_button(t_game *game, void *box)
{
	int			x;
	int			y;
	t_button	*button;

	button = box;
	y = button->box.y;
	while (y < button->box.y + button->box.height)
	{
		x = button->box.x;
		while (x < button->box.x + button->box.width)
		{
			if (x < button->box.x + BORDER_SIZE
				|| x > button->box.x + button->box.width - BORDER_SIZE
				|| y < button->box.y + BORDER_SIZE
				|| y > button->box.y + button->box.height - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
			else
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x111111);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_button_end(t_game *game, void *box)
{
	int			x;
	int			y;
	t_button	*button;

	button = box;
	y = button->box.y;
	while (y < button->box.y + button->box.height)
	{
		x = button->box.x;
		while (x < button->box.x + button->box.width)
		{
			if (x < button->box.x + BORDER_SIZE
				|| x > button->box.x + button->box.width - BORDER_SIZE
				|| y < button->box.y + BORDER_SIZE
				|| y > button->box.y + button->box.height - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0xAAAAAA);
			else
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x111111);
			x++;
		}
		y++;
	}
	return (0);
}

int	draw_button_start(t_game *game, void *box)
{
	int			x;
	int			y;
	t_button	*button;

	button = box;
	y = button->box.y;
	while (y < button->box.y + button->box.height)
	{
		x = button->box.x;
		while (x < button->box.x + button->box.width)
		{
			if (x < button->box.x + BORDER_SIZE
				|| x > button->box.x + button->box.width - BORDER_SIZE
				|| y < button->box.y + BORDER_SIZE
				|| y > button->box.y + button->box.height - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
			else
				my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x111111);
			x++;
		}
		y++;
	}
	return (0);
}
