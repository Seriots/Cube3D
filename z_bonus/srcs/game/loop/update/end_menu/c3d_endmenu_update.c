/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_endmenu_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:42:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 19:13:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"

#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	make_border_end(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < END_HEIGHT)
	{
		x = 0;
		while (x < END_WIDTH)
		{
			if (x < END_BORDER_SIZE || x >= END_WIDTH - END_BORDER_SIZE
				|| y < END_BORDER_SIZE || y >= END_HEIGHT - END_BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0xAAAAAA);
			x++;
		}
		y++;
	}
	return (0);
}

int	make_background_end(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < END_HEIGHT)
	{
		x = 0;
		while (x < END_WIDTH)
		{
			if (x < END_BORDER_SIZE || x >= END_WIDTH - END_BORDER_SIZE
				|| y < END_BORDER_SIZE || y >= END_HEIGHT - END_BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0xDDDDDD);
			else if (y <= ((15 * MENU_HEIGHT / 100)))
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x353535);
			else if (y >= (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x282828);
			else
				my_mlx_pixel_put(&game->all_img.end_img, x, y, 0x222222);
			x++;
		}
		y++;
	}
	return (0);
}

int	endmenu_update(t_game *game)
{
	if (game->is_update == 0
		&& game->last_frame - game->load_start_frame
		> END_ANIMATION_DURATION * 2)
		return (0);
	make_background_end(game);
	draw_all_objects(game, game->end_menu.all_objects);
	make_border_end(game);
	game->is_update = 0;
	game->is_display = 1;
	return (0);
}
