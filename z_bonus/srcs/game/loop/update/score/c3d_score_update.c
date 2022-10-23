/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_score_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:53:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/23 16:45:44 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"

#include "ft.h"

int	draw_score_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCOREMENU_HEIGHT)
	{
		x = 0;
		while (x < SCOREMENU_WIDTH)
		{
			if (x < BORDER_SIZE || x > SCOREMENU_WIDTH - BORDER_SIZE || y < BORDER_SIZE
				|| y > SCOREMENU_HEIGHT - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.screen_img,
				x + WIN_WIDTH / 2 - SCOREMENU_WIDTH / 2,
				y + 50, 0xDDDDDD);
			else
				my_mlx_pixel_put(&game->all_img.screen_img,
				x + WIN_WIDTH / 2 - SCOREMENU_WIDTH / 2,
				y + 50, 0x222222);
			x++;
		}
		y++;
	}
	return (0);
}

int	score_update(t_game *game)
{
	start_raycasting(game);
	start_display_all_sprites(game);
	draw_score_background(game);
	draw_all_objects(game, game->score_menu.all_objects);
	update_camera(game);
	return (0);
}
