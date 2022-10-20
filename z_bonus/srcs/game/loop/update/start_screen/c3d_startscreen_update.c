/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen_update.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:53:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 11:10:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"

#include "ft.h"

int	make_background_startscreen(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (x < BORDER_SIZE || x >= WIN_WIDTH - BORDER_SIZE
				|| y < BORDER_SIZE || y >= WIN_HEIGHT - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xDDDDDD);
			else
				my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x222222);
			x++;
		}
		y++;
	}
	return (0);
}

int	update_camera(t_game *game)
{
	game->start_map.player.plane.value += 0.00001 * game->delay;
	game->player.angleup = cos(game->start_map.player.plane.value);
	if (game->start_map.player.plane.value > 2 * M_PI)
		game->start_map.player.plane.value -= 2 * M_PI;
	game->start_map.player.plane.cos = cos(game->start_map.player.plane.value);
	game->start_map.player.plane.sin = sin(game->start_map.player.plane.value);
	game->start_map.player.plane.tan = tan(game->start_map.player.plane.value);
	return (0);
}

int	startscreen_update(t_game *game)
{
	//make_background_startscreen(game);
	start_raycasting(game);
	start_display_all_sprites(game);
	draw_all_objects(game, game->start_menu.all_objects);
	update_camera(game);
	return (0);
}
