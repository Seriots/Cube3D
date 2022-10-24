/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichoice_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:06:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/23 18:03:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_menu.h"

int	multichoice_press(int button, int x, int y, t_game *game)
{
	t_multichoice	*multichoice;

	(void)y;
	if (button == 1)
	{
		multichoice = dict_getelem_number(game->start_menu.all_objects,
				game->pick_obj)->value;
		if (x <= multichoice->box.x + multichoice->box.width / 8)
			*multichoice->modified_value -= 1;
		else if (x >= multichoice->box.x + 7 * (multichoice->box.width / 8))
			*multichoice->modified_value += 1;
		if (*multichoice->modified_value < 0)
			*multichoice->modified_value = multichoice->max;
		else if (*multichoice->modified_value > multichoice->max)
			*multichoice->modified_value = 0;
	}
	return (0);
}

int	multichoice_press_score(int button, int x, int y, t_game *game)
{
	t_multichoice	*multichoice;
	t_dict			*scrollbar;

	(void)y;
	if (button == 1)
	{
		multichoice = dict_getelem_number(game->score_menu.all_objects,
				game->pick_obj)->value;
		if (x <= multichoice->box.x + multichoice->box.width / 8)
			*multichoice->modified_value -= 1;
		else if (x >= multichoice->box.x + 7 * (multichoice->box.width / 8))
			*multichoice->modified_value += 1;
		if (*multichoice->modified_value < 0)
			*multichoice->modified_value = multichoice->max;
		else if (*multichoice->modified_value > multichoice->max)
			*multichoice->modified_value = 0;
		scrollbar = dict_getelem_key(game->score_menu.all_objects, SCROLLBAR3);
		if (scrollbar)
			set_height_s(game, scrollbar->value, get_score_array(game));
		game->score_menu.scroll_amount = 0;
	}
	return (0);
}
