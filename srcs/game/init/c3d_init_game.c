/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 11:50:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_init.h"
#include "c3d_loop.h"
#include "c3d_settings.h"

static int	set_default_fcts(t_game *game)
{
	game->fcts.update_fct = default_update;
	game->fcts.display_fct = default_display;
	game->fcts.keypressed_fct = default_key_press;
	game->fcts.keyreleased_fct = default_key_release;
	game->fcts.mousepressed_fct = default_mouse_press;
	game->fcts.mousereleased_fct = default_mouse_release;
	game->fcts.mousemove_fct = default_mouse_move;
	return (0);
}

static int	set_default_settings(t_game *game)
{
	game->settings.fps = FPS;
	game->settings.fov = FOV;
	game->settings.sensibility = SENSIBILITY;
	game->settings.left = DEFAULT_LEFT;
	game->settings.right = DEFAULT_RIGHT;
	game->settings.forward = DEFAULT_FORWARD;
	game->settings.backward = DEFAULT_BACKWARD;
	game->settings.turn_left = DEFAULT_TURN_LEFT;
	game->settings.turn_right = DEFAULT_TURN_RIGHT;
	game->settings.pause = DEFAULT_PAUSE;
	return (0);
}

int	init_game(t_game *game, int first)
{
	int	error;

	if (first)
		set_default_fcts(game);
	if (first)
		set_default_settings(game);
	error = init_player(game);
	if (error)
		return (error);
	error = init_images(game);
	if (error)
		return (error);
	return (0);
}
