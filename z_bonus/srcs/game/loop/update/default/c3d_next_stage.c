/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_next_stage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:31:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 15:14:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "c3d_menu.h"

#include "mlx.h"
#include "ft.h"

#include <time.h>
#include <stdlib.h>

#include <stdio.h>

int	loading(t_game *game)
{
	int			error;

	if (game->last_frame - game->load_start_frame > LOADING_DURATION)
	{
		game->settings.seed = time(0);
		error = load_new_map(game, 0, 0);
		if (error)
			return (load_startscreen(game),
				set_error_value(&game->start_menu, error),
				display_error(error));
		game->level += 1;
		game->player.stats.level.value += 1;
		set_map_settings(game, &game->menu.all_objects);
	}
	return (0);
}

int	display_loading_message(t_game *game)
{
	const char	message[][256] = {"Jouez c rigolo !", "Avis a tous les usagers de poste 126, veuillez vous soumettre au control annuel des droits regionaux, Cordialement la prefecture."};
	int			r;
	
	r = game->settings.seed % (sizeof(message) / sizeof(message[0]));
	mlx_string_put(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen(message[r]) / 2), WIN_HEIGHT / 2 - 100,
		0xDDDDDD, (char *)message[r]);
	return (0);
}

int	loading_display(t_game *game)
{
	long int	frame;
	int			image_value;
	
	frame = (game->last_frame - game->load_start_frame) % 600;
	image_value = frame / (600 / 15);
	if (image_value >= 15)
		image_value = 15 - 1;
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.all_loading_img[image_value].img, WIN_WIDTH - 60,
			WIN_HEIGHT - 20 - game->all_img.all_loading_img[image_value].height);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.loading.img, WIN_WIDTH - 300,
			WIN_HEIGHT - 10 - game->all_img.loading.height);
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	fade_display(t_game *game)
{
	mlx_put_image_to_window(game->mlx.display,
		game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	fade_update_loop(t_game *game, float percent, int limit_x, int limit_y)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= limit_y)
	{
		x = -1;
		while (++x <= limit_x)
		{
			my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x000000);
			my_mlx_pixel_put(&game->all_img.screen_img,
				WIN_WIDTH - x, y, 0x000000);
			my_mlx_pixel_put(&game->all_img.screen_img,
				x, WIN_HEIGHT - y, 0x000000);
			my_mlx_pixel_put(&game->all_img.screen_img,
				WIN_WIDTH - x, WIN_HEIGHT - y, 0x000000);
		}
	}
	if (percent == 1)
	{
		fade_display(game);
		game->load_start_frame = game->last_frame;
		game->fcts.update_fct = loading;
		game->fcts.display_fct = loading_display;
		display_loading_message(game);
	}
	return (0);
}

int	fade_update(t_game *game)
{
	float	percent;
	int		limit_x;
	int		limit_y;

	percent = ((float)(game->last_frame - game->load_start_frame)
			/ FADE_DURATION);
	if (percent > 1)
		percent = 1;
	limit_x = percent * (WIN_WIDTH / 2);
	limit_y = percent * (WIN_HEIGHT / 2);
	fade_update_loop(game, percent, limit_x, limit_y);
	return (0);
}


int	next_stage(t_game *game)
{
	game->fcts.keypressed_fct = 0;
	game->fcts.keyreleased_fct = 0;
	game->fcts.mousepressed_fct = 0;
	game->fcts.mousereleased_fct = 0;
	game->fcts.mousemove_fct = 0;
	game->fcts.update_fct = fade_update;
	game->fcts.display_fct = fade_display;
	game->load_start_frame = game->last_frame;
	if (100000 - (game->last_frame - game->map_start_frame) < 0)
		game->player.stats.score.value += game->player.stats.level.value * 1000;
	else
		game->player.stats.score.value += game->player.stats.level.value
		* (1000 + (100000 - (game->last_frame - game->map_start_frame)) / 100);
		
	free_textures(game, &game->all_img);
	free_map_with_inventory(game, &game->map);
	return (0);
}
