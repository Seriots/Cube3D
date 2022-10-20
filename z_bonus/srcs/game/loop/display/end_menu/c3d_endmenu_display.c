/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_endmenu_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 22:17:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	endmenu_display(t_game *game)
{
	if (game->is_display == 0)
		return (0);
	my_mlx_put_image_to_window(
		game, &game->all_img.end_img,
		WIN_WIDTH / 2 - ENDMENU_WIDTH / 2,
		WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	display_text(game, game->end_menu.all_objects);
	game->is_display = 0;
	return (0);
}
