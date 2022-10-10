/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:49:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:38:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include "mlx.h"

int	startscreen_display(t_game *game)
{
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	display_text(game, game->start_menu.all_objects);
	if (game->start_menu.error != 0)
		display_error_on_screen(game, get_error(game->start_menu.error),
			START_MENU_ERROR_X, START_MENU_ERROR_Y);
	return (0);
}
