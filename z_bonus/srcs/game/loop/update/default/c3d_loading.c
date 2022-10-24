/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:03:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 19:04:10 by lgiband          ###   ########.fr       */
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
	const char	message[][256] = {"Jouez c'est rigolo !",
		"Bon toutou", "Avec un peu de chocolat, c'est toujours meilleur",
		"TFT > LOL", "TOURTE BATTLE ROYALE > FORTNITE > CSGO > VALORANT",
		"C'est pas la peine de faire la gueule, \
c'est pas comme si t'as le choix",
		"C'est toujours mieux que minishell", "ping .............. pong",
		"1, 2, 3, pierre feuille ciseaux.......... pierre",
		"1, 2, 3, pierre feuille ciseaux.......... feuille",
		"1, 2, 3, pierre feuille ciseaux.......... ciseaux",};
	int			r;

	r = game->settings.seed % (sizeof(message) / sizeof(message[0]));
	mlx_string_put(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen(message[r]) / 2),
		WIN_HEIGHT / 2 - 100,
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
