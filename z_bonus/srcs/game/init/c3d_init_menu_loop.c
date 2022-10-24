/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_menu_loop.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:04:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 18:04:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_startscreen.h"
#include "c3d_menu.h"

#include "ft.h"
#include "dict.h"

#include <stdio.h>

int	init_settings_menu2(t_game *game)
{
	static t_dict		*(*objs[])(t_game *game) = {init_slot1_keyinput,
		init_slot2_keyinput, init_slot3_keyinput, init_slot4_keyinput,
		init_slot5_keyinput, init_slot6_keyinput, init_slot7_keyinput,
		init_slot8_keyinput, init_run_keyinput, init_crouch_keyinput,
		init_scrollbar};
	long unsigned int	i;
	t_dict				*elem;

	i = -1;
	while (++i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (10);
		dict_add_back(&game->menu.all_objects, elem);
	}
	return (0);
}

int	init_settings_menu(t_game *game)
{
	static t_dict		*(*objs[])(t_game *game) = {init_resume_button,
		init_exit_button, init_fov_slidebar, init_color_checkbox,
		init_forward_keyinput, init_left_keyinput, init_textinput_north,
		init_numinput_floor, init_backward_keyinput, init_right_keyinput,
		init_textinput_south, init_textinput_east, init_textinput_west,
		init_textinput_floor, init_textinput_ceil,
		init_numinput_ceil, init_scrollspeed_slidebar, init_showseed_checkbox,
		init_invertscroll_checkbox, init_camspeedx_slidebar,
		init_camspeedy_slidebar, init_showfps_checkbox, init_showmmap_checkbox,
		init_invertmouse_checkbox, init_resolution_slidebar, init_fps_slidebar,
		init_drop_keyinput, init_interact_keyinput};
	long unsigned int	i;
	t_dict				*elem;

	i = -1;
	game->menu = (t_menu){.scroll_amount = 0, .error = 0};
	while (++i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (10);
		dict_add_back(&game->menu.all_objects, elem);
	}
	return (0);
}

int	init_start_menu(t_game *game)
{
	static t_dict		*(*objs[])(t_game *game) = {init_multichoice_difficulty,
		init_play_button, init_quit_button, init_seed, init_textinput_mappath,
		init_score_button};
	t_dict				*elem;
	long unsigned int	i;

	i = 0;
	while (i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (10);
		dict_add_back(&game->start_menu.all_objects, elem);
		i++;
	}
	game->start_menu.error = 0;
	game->start_menu.scroll_amount = 0;
	game->end_menu.scroll_amount = 0;
	return (0);
}

int	init_score_menu(t_game *game)
{
	static t_dict		*(*objs[])(t_game *game) = {
		init_multichoice_difficulty_score,
		init_return_button, init_scrollbar_score};
	t_dict				*elem;
	long unsigned int	i;

	i = 0;
	while (i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (10);
		dict_add_back(&game->score_menu.all_objects, elem);
		i++;
	}
	game->score_menu.error = 0;
	game->score_menu.scroll_amount = 0;
	return (0);
}

int	init_end_menu(t_game *game)
{
	static t_dict		*(*objs[])(t_game *game) = {init_retry_button,
		init_mainmenu_button, init_nameinput_end, init_scrollbar_end};
	t_dict				*elem;
	long unsigned int	i;

	i = 0;
	while (i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (10);
		dict_add_back(&game->end_menu.all_objects, elem);
		i++;
	}
	game->end_menu.error = 0;
	game->end_menu.scroll_amount = 0;
	return (0);
}
