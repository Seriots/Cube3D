/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "c3d_struct_bonus.h"
#include "c3d_event_bonus.h"
#include "c3d_init_bonus.h"
#include "c3d_loop_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_utils_bonus.h"

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
	game->settings.scroll_speed = SCROLL_SPEED;
	game->settings.cam_sensibility_x = CAM_SENSIBILITY_X;
	game->settings.cam_sensibility_y = CAM_SENSIBILITY_Y;
	game->settings.resolution = RESOLUTION;
	game->settings.left = XK_a;
	game->settings.right = XK_d;
	game->settings.forward = XK_w;
	game->settings.backward = XK_s;
	game->settings.turn_left = XK_Left;
	game->settings.turn_right = XK_Right;
	game->settings.pause = XK_Escape;
	game->settings.color = 1;
	game->settings.invert_scroll = 0;
	game->settings.invert_mouse = 0;
	game->settings.show_fps = 0;
	return (0);
}

static int	set_variable(t_game *game)
{
	game->last_frame = timestamp_msec(0);
	game->delay = 0;
	game->menu.all_objects = 0;
	game->all_img.menu_img.img = NULL;
	game->all_img.screen_img.img = NULL;
	game->all_img.minimap_img.img = NULL;
	game->all_img.all_cursor_img = NULL;
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
	error = init_menu(game);
	if (error)
		return (error);
	return (0);
}