/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 15:28:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_init.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

static int	set_default_fcts(t_game *game)
{
	game->fcts.update_fct = default_update;
	game->fcts.display_fct = default_display;
	game->fcts.keypressed_fct = default_key_press;
	game->fcts.keyreleased_fct = default_key_release;
	return (0);
}

static int	set_default_settings(t_game *game)
{
	game->settings.fps = FPS;
	game->settings.fov = FOV;
	game->settings.sensibility = SENSIBILITY;
	game->settings.left = XK_a;
	game->settings.right = XK_d;
	game->settings.forward = XK_w;
	game->settings.backward = XK_s;
	game->settings.turn_left = XK_Left;
	game->settings.turn_right = XK_Right;
	game->settings.pause = XK_Escape;
	return (0);
}

static int	set_variable(t_game *game)
{
	game->last_frame = 0;
	game->delay = 0;
	return (0);
}

int	init_game(t_game *game, int first)
{
	int	error;

	if (first)
		set_default_fcts(game);
	if (first)
		set_default_settings(game);
	set_variable(game);
	error = init_player(game);
	if (error)
		return (error);
	error = init_images(game);
	if (error)
		return (error);
	return (0);
}
