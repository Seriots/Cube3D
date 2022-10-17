/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 16:40:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "c3d_loop.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

int	show_fps(t_game *game)
{
	char	fps[32];

	ft_itoa_noalloc(fps, 1000 / game->delay);
	ft_strlcat(fps, " fps", 32);
	mlx_string_put(game->mlx.display, game->mlx.window, 10, 15, 0xFFFFFF, fps);
	return (0);
}

int	show_seed(t_game *game)
{
	char	seed[32];

	ft_itoal_noalloc(seed, game->settings.seed);
	mlx_string_put(game->mlx.display, game->mlx.window, WIN_WIDTH
		- 10 - (FONT_WIDTH * ft_strlen(seed)), 15, 0xFFFFFF, seed);
	return (0);
}

int	display_bar(t_game *game)
{
	t_dict	*dict;

	display_staminabar(game);
	display_lifebar(game);
	if (game->inventory.selected >= 0)
	{
		dict = dict_getelem_ptr(game->map.all_objects, game->inventory.items[game->inventory.selected]);
		if (dict && ft_strcmp(dict->key, LAMP) == 0)
			display_lightbar(game, dict->value);
	}
	return (0);
}

int	display_game_error(t_game *game)
{
	if (game->error.start_time + game->error.duration > game->last_frame)
		mlx_string_put(game->mlx.display, game->mlx.window,
			WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen(game->error.message) / 2),
			5 * WIN_HEIGHT / 6, 0xFF0000, game->error.message);
	return (0);
}

int	default_display(t_game *game)
{
	raycasting(game);
	if (game->settings.show_mmap)
		my_mlx_put_image_to_window(game, &game->all_img.minimap_img,
			10, WIN_HEIGHT - game->all_img.minimap_img.height - 10);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	if (game->settings.show_fps)
		show_fps(game);
	if (game->settings.show_seed)
		show_seed(game);
	display_bar(game);
	display_hand(game);
	display_inventory(game);
	display_game_error(game);
	return (0);
}
