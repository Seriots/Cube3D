/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_mainmenu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:09:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 10:41:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"
#include "dict.h"

#include <stdio.h>

int	mainmenu_event(int button, int x, int y, t_game *game)
{
	t_scrollbar	*scrollbar;

	(void)x;
	(void)y;
	if (button == 1)
	{
		free_textures(game, &game->all_img);
		free_map_with_inventory(game, &game->map);
		add_scores(game, get_score_array(game), game->settings.name, game->player.stats.score.value);
		sort_scores(get_score_array(game));
		save_scores(game, get_score_array(game), get_score_file(game));
		scrollbar = dict_getelem_key(game->end_menu.all_objects, SCROLLBAR2)->value;
		load_startscreen(game);
		game->menu.scroll_amount = 0;
		if (scrollbar)
			scrollbar->box.y = scrollbar->min;
		clear_all_other_selected(game, NULL, game->end_menu.all_objects);
	}
	return (0);
}

t_dict	*init_mainmenu_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 50;
	box->box.width = 200;
	box->box.x = ENDMENU_WIDTH / 2 - box->box.width - 5;
	box->box.y = ENDMENU_HEIGHT - box->box.height - 20;
	ft_strlcpy(box->box.description, "Main menu", 10);
	box->box.y_text = box->box.y + 30;
	box->box.x_text = box->box.x + box->box.width / 2 - (FONT_WIDTH * ft_strlen(box->box.description) / 2);
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = mainmenu_event;
	dict = dict_new(BUTTON3, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
