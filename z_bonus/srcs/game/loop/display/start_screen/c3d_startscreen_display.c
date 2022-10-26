/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:49:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 12:11:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include "mlx.h"

int	startscreen_display(t_game *game)
{
	my_mlx_put_image_to_window(game, &game->all_img.leaderboard,
		WIN_WIDTH - 100 + (80 - game->all_img.leaderboard.width) / 2,
		20 + (80 - game->all_img.leaderboard.height) / 2);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	display_text(game, game->start_menu.all_objects);
	if (game->start_menu.error != 0)
		display_error_on_screen(game, get_error(game->start_menu.error),
			START_MENU_ERROR_X, START_MENU_ERROR_Y);
	return (0);
}
