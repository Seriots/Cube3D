/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 17:53:30 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

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
	t_object	*obj;

	display_staminabar(game);
	display_lifebar(game);
	if (game->inventory.selected >= 0)
	{
		obj = game->inventory.items[game->inventory.selected];
		if (obj && ft_strcmp(obj->tag, LAMP) == 0)
			display_lightbar(game, obj);
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

int	display_level(t_game *game)
{
	char	level[32];
	char	lvl[32];
	
	ft_itoa_noalloc(lvl, game->level);
	ft_strlcpy(level, "Level : ", 32);
	ft_strlcat(level, lvl, 32);
	mlx_string_put(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen("Level : ") / 2),
		WIN_HEIGHT / 14, 0xDDDDDD, level);
	return (0);
}

static int	set_cursor(t_game *game)
{
	int	x;
	int	y;

	y = -5;
	while (y < 5)
	{
		x = -5;
		while (x < 5)
		{
			if (norm(x, y) < 2)
				my_mlx_pixel_put(&game->all_img.screen_img, WIN_WIDTH / 2 + x, WIN_HEIGHT / 2 + y, 0xDDDDDD);
			x++;
		}
		y++;
	}
	return (0);
}

int	default_display(t_game *game)
{
	raycasting(game);
	display_all_sprites(game);
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
	display_level(game);
	set_cursor(game);
	return (0);
}
