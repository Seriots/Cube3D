/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:07:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 22:26:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_init.h"
#include "c3d_utils.h"
#include "c3d_menu.h"

#include "ft.h"
#include "dict.h"

int	exit_event(int button, int x, int y, t_game *game)
{
	int	error;

	(void)x;
	(void)y;
	if (button == 1)
	{
		error = save_settings(game);
		if (error)
			display_error(error);
		game->settings.seed = 0;
		free_textures(game, &game->all_img);
		free_map(&game->map);
		clear_all_other_selected(game, 0, game->menu.all_objects);
		load_startscreen(game);
	}
	return (0);
}

t_dict	*init_exit_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 50;
	box->box.width = 200;
	box->box.x = MENU_WIDTH / 2 + 5;
	box->box.y = MENU_HEIGHT - box->box.height - 20;
	box->box.x_text = box->box.x + 90;
	box->box.y_text = box->box.y + 30;
	ft_strlcpy(box->box.description, "Exit", 5);
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = exit_event;
	dict = dict_new(BUTTON, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
