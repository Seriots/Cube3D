/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:43:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 12:52:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "ft.h"
#include "mlx.h"

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
				my_mlx_pixel_put(&game->all_img.screen_img,
					WIN_WIDTH / 2 + x, WIN_HEIGHT / 2 + y, 0xDDDDDD);
			x++;
		}
		y++;
	}
	return (0);
}

int	is_map_in_hand(t_game *game)
{
	if (game->inventory.selected == -1)
		return (0);
	if (game->inventory.items[game->inventory.selected] == NULL)
		return (0);
	if (ft_strcmp(game->inventory.items[game->inventory.selected]->tag,
			MAP) == 0 && game->inventory.items[game->inventory.selected]->state
		== game->level)
		return (1);
	return (0);
}

int	display_screen(t_game *game)
{
	int	i;
	int	j;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			my_mlx_pixel_put(&game->all_img.screen_img,
				i, j, shade_pixel(game, i, j));
	}
	return (0);
}

int	default_display(t_game *game)
{
	raycasting(game);
	display_all_sprites(game);
	display_screen(game);
	if (game->settings.show_mmap || is_map_in_hand(game))
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
