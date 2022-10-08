/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 12:51:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "ft.h"
#include "mlx.h"

int	show_fps(t_game *game)
{
	char	fps[32];

	ft_itoa_noalloc(fps, 1000 / game->delay);
	ft_strlcat(fps, " fps", 24);
	mlx_string_put(game->mlx.display, game->mlx.window, 10, 10, 0xFFFFFF, fps);
	return (0);
}

int	default_display(t_game *game)
{
	raycasting(game);
	my_mlx_put_image_to_window(game, &game->all_img.minimap_img,
		10, WIN_HEIGHT - game->all_img.minimap_img.height - 10);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	if (game->settings.show_fps)
		show_fps(game);
	return (0);
}
