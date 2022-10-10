/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:26:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_init.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_startscreen.h"

#include "ft.h"

static int	set_default_fcts(t_game *game)
{
	load_startscreen(game);
	return (0);
}

static int	set_default_settings(t_game *game, char *path)
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
	game->settings.show_seed = 0;
	game->settings.show_mmap = 1;
	game->settings.seed = 0;
	game->settings.difficulty = 0;
	game->settings.map_path = ft_strdup(path);
	if (path && !game->settings.map_path)
		return (10);
	return (0);
}

static int	set_variable(t_game *game)
{
	game->last_frame = timestamp_msec(0);
	game->delay = 0;
	game->menu.all_objects = 0;
	game->start_menu.all_objects = 0;
	game->all_img.menu_img.img = NULL;
	game->all_img.screen_img.img = NULL;
	game->all_img.minimap_img.img = NULL;
	game->all_img.all_cursor_img = NULL;
	game->map = (t_map){.c = -1, .f = -1, .ea = NULL, .no = NULL, .so = NULL,
		.we = NULL, .height = 0, .width = 0, .all_objects = 0};
	return (0);
}

int	init_game(t_game *game, char *path)
{
	int	error;

	set_variable(game);
	set_default_fcts(game);
	error = set_default_settings(game, path);
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
/*
	error = init_player(game);
	if (error)
		return (error);
*/