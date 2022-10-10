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
#include "mzg_incs.h"
#include "c3d_parsing.h"

#include "ft.h"
#include "dict.h"

int	load_new_map(t_game *game, char *map_path)
{
	int	error;

	if (map_path)
	{
		error = parsing(&(game->map), map_path);
		if (error)
			return (free_map(&game->map), display_error(error));
	}
	else
	{
		error = get_maze(&game->map, 50, 50 ,12); //add seed, difficulty....
		if (error)
			return (free_map(&game->map), display_error(error));
	}
	error = init_player(game);
	if (error)
		return (free_map(&game->map), display_error(error));
	error = open_textures(game, &game->map);
	if (error)
		return (free_map(&game->map), display_error(error));
	load_default(game);
	return (0);
}

int	set_map_settings(t_game *game, t_dict **menu)
{
	t_dict *tmp;

	(void)game;
	tmp = *menu;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, TEXTINPUT) == 0)
			init_textinput((t_textinput *)tmp->value);
		else if (ft_strcmp(tmp->key, NUMINPUT) == 0)
			edit_rgb((t_numinput *)tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

int	play_event(int button, int x, int y, t_game *game)
{
	int	error;

	(void)x;
	(void)y;
	if (button == 1)
	{
		error = load_new_map(game, game->settings.map_path);
		if (error)
			return (set_error_value(&game->start_menu, error), error);
		set_map_settings(game, &game->menu.all_objects);
		clear_all_other_selected(game, NULL, game->start_menu.all_objects);
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
	box->box.y = (WIN_HEIGHT / 3 - box->box.height / 2);
	ft_strlcpy(box->box.description, "Play", 5);
	box->box.x_text = box->box.x + box->box.width / 2 - (6 * ft_strlen(box->box.description) / 2);
	box->box.y_text = box->box.y + box->box.height / 2 + 10 / 2;
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = play_event;
	dict = dict_new(BUTTON2, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
