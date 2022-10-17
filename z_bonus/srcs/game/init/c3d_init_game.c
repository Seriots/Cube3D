/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 17:54:59 by lgiband          ###   ########.fr       */
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
#include "mzg_incs.h"

#include "ft.h"

static int	set_default_fcts(t_game *game)
{
	load_startscreen(game);
	return (0);
}

static int	set_default_settings2(t_game *game)
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
	game->settings.turn_up = XK_Up;
	game->settings.turn_down = XK_Down;
	game->settings.pause = XK_Escape;
	game->settings.interact = XK_e;
	game->settings.drop = XK_z;
	game->settings.slot1 = XK_1;
	game->settings.slot2 = XK_2;
	game->settings.slot3 = XK_3;
	game->settings.slot4 = XK_4;
	game->settings.slot5 = XK_5;
	game->settings.slot6 = XK_6;
	game->settings.slot7 = XK_7;
	game->settings.slot8 = XK_8;
	return (0);
}

static int	set_default_settings(t_game *game, char *path)
{
	game->settings.run = XK_Shift_L;
	game->settings.crouch = XK_Control_L;
	game->settings.color = 1;
	game->settings.invert_scroll = 0;
	game->settings.invert_mouse = 0;
	game->settings.show_fps = 0;
	game->settings.show_seed = 0;
	game->settings.show_mmap = 1;
	game->settings.seed = 0;
	game->settings.difficulty = 0;
	ft_strlcpy(game->map.default_ceil, DEFAULT_CEIL, 256);
	ft_strlcpy(game->map.default_floor, DEFAULT_FLOOR, 256);
	ft_strlcpy(game->map.default_north, DEFAULT_IMAGE_PATH_NO, 256);
	ft_strlcpy(game->map.default_south, DEFAULT_IMAGE_PATH_SO, 256);
	ft_strlcpy(game->map.default_west, DEFAULT_IMAGE_PATH_WE, 256);
	ft_strlcpy(game->map.default_east, DEFAULT_IMAGE_PATH_EA, 256);
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
	game->pick_obj = 0;
	game->error.start_time = 0;
	game->error.duration = 0;
	game->error.message[0] = 0;
	game->all_img.menu_img.img = NULL;
	game->all_img.screen_img.img = NULL;
	game->all_img.minimap_img.img = NULL;
	game->all_img.all_cursor_img = NULL;
	game->all_img.flashlight[0].img = NULL;
	game->all_img.flashlight[1].img = NULL;
	game->all_img.flashlight[2].img = NULL;
	game->all_img.key[0].img = NULL;
	game->all_img.key[1].img = NULL;
	game->all_img.key[2].img = NULL; //proteger tous les obj
	game->level = 1;
	game->inventory.base_hand = (t_coord){.x = 0, .y = 0};
	game->inventory.current_hand = game->inventory.base_hand;
	game->map = (t_map){.c = -1, .f = -1, .ea = NULL, .no = NULL, .so = NULL,
		.we = NULL, .height = 0, .width = 0, .all_objects = 0, .map = NULL};
	return (0);
}

int	init_game(t_game *game, char *path)
{
	int	error;

	set_variable(game);
	set_default_fcts(game);
	set_default_settings2(game);
	error = set_default_settings(game, path);
	if (error)
		return (error);
	error = load_settings(game);
	if (error)
		display_error(error);
	error = init_images(game);
	if (error)
		return (error);
	error = init_menu(game);
	if (error)
		return (error);
	return (0);
}
