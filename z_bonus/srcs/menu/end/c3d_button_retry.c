/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_retry.c                                  :+:      :+:    :+:   */
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
#include "c3d_loop.h"

#include "ft.h"
#include "dict.h"

int	retry_event(int button, int x, int y, t_game *game)
{
	int	error;

	(void)x;
	(void)y;
	if (button == 1)
	{
		add_scores(game, get_score_array(game), game->settings.name, game->player.stats.score.value);
		save_scores(game, get_score_array(game), get_score_file(game));
		error = load_new_map(game, game->settings.map_path, 1);
		if (error)
			return (set_error_value(&game->end_menu, error), error);
		set_map_settings(game, &game->menu.all_objects);
		set_inventory(game);
	}
	return (0);
}

t_dict	*init_retry_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 50;
	box->box.width = 200;
	box->box.x = ENDMENU_WIDTH / 2 + 5;
	box->box.y = ENDMENU_HEIGHT - box->box.height - 20;
	ft_strlcpy(box->box.description, "Retry", 6);
	box->box.y_text = box->box.y + 30;
	box->box.x_text = box->box.x + box->box.width / 2 - (FONT_WIDTH * ft_strlen(box->box.description) / 2);
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = retry_event;
	dict = dict_new(BUTTON3, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
