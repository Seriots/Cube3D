/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_play.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:09:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 13:34:32 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "c3d_loop.h"
#include "mzg_incs.h"
#include "c3d_parsing.h"
#include "c3d_object.h"

#include "ft.h"
#include "dict.h"

#include <stdio.h>

int	set_inventory(t_game *game)
{
	t_dict	*elem;

	ft_bzero(game->inventory.items, sizeof(game->inventory.items));
	if (game->settings.difficulty == 0)
		game->inventory.size = 8;
	else if (game->settings.difficulty == 1)
		game->inventory.size = 6;
	else
		game->inventory.size = 4;
	game->inventory.selected = -1;
	elem = dict_get_last(game->map.all_objects);
	if (elem && ft_strcmp(elem->key, LAMP) == 0)
		add_items(game, &game->inventory, elem->value);
	return (0);
}

int	play_event(int button, int x, int y, t_game *game)
{
	int	error;

	(void)x;
	(void)y;
	if (button == 1)
	{
		clear_all_other_selected(game, NULL, game->start_menu.all_objects);
		error = load_new_map(game, game->settings.map_path, 1);
		if (error)
			return (set_error_value(&game->start_menu, error), error);
		set_map_settings(game, &game->menu.all_objects);
		set_inventory(game);
		error = save_settings(game);
		if (error)
			display_error(error);
	}
	return (0);
}

t_dict	*init_play_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 100;
	box->box.width = 300;
	box->box.x = WIN_WIDTH / 2 - box->box.width / 2;
	box->box.y = (WIN_HEIGHT / 3 - box->box.height / 2) + 70;
	ft_strlcpy(box->box.description, "Play", 5);
	box->box.x_text = box->box.x + box->box.width / 2
		- (FONT_WIDTH * ft_strlen(box->box.description) / 2);
	box->box.y_text = box->box.y + box->box.height / 2 + 10 / 2;
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = play_event;
	dict = dict_new(BUTTON2, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
