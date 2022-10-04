/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_resume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:09:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 23:56:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_utils.h"

#include "ft.h"
#include "dict.h"

int	resume_event(int button, int x, int y, t_game *game)
{
	t_scrollbar	*scrollbar;

	(void)x;
	(void)y;
	if (button == 1)
	{
		scrollbar = dict_getelem_key(game->menu.all_objects, SCROLLBAR)->value;
		close_menu(game);
		game->menu.scroll_amount = 0;
		scrollbar->box.y = scrollbar->min;
		clear_all_other_selected(game, NULL);
	}
	return (0);
}

t_dict	*init_resume_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 50;
	box->box.width = 200;
	box->box.x = MENU_WIDTH / 2 - box->box.width - 5;
	box->box.y = MENU_HEIGHT - box->box.height - 20;
	box->box.x_text = box->box.x + 90;
	box->box.y_text = box->box.y + 30;
	ft_strlcpy(box->box.description, "Resume", 7);
	ft_strlcpy(box->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	box->box.mouse_press = NULL;
	box->box.mouse_release = resume_event;
	dict = dict_new(BUTTON, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
