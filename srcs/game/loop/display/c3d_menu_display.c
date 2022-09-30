/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 18:28:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "mlx.h"

int	menu_display(t_game *game)
{
	my_mlx_put_image_to_window(
		game,
		&game->all_img.menu_img,
		WIN_WIDTH / 2 - MENU_WIDTH / 2,
		WIN_HEIGHT / 2 - MENU_HEIGHT / 2
	);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window, game->all_img.screen_img.img, 0, 0);
	return (0);
}