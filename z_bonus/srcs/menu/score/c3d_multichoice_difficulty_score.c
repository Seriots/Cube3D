/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_multichoice_difficulty.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:43:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/23 16:24:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

#include <stdio.h>

void	set_multichoice_difficulty_score(t_game *game, t_multichoice *multichoice)
{
	multichoice->min = 0;
	multichoice->max = 2;
	ft_strlcpy(multichoice->all_values[0], "EASY", 5);
	ft_strlcpy(multichoice->all_values[1], "MEDIUM", 7);
	ft_strlcpy(multichoice->all_values[2], "HARD", 5);
	multichoice->modified_value = &game->settings.difficulty;
}

t_dict	*init_multichoice_difficulty_score(t_game *game)
{
	t_multichoice	*multichoice;
	t_dict			*obj;

	multichoice = malloc(sizeof(t_multichoice));
	if (!multichoice)
		return (0);
	set_multichoice_difficulty_score(game, multichoice);
	multichoice->box.height = 24;
	multichoice->box.width = 200;
	multichoice->box.x = WIN_WIDTH / 2 - multichoice->box.width / 2;
	multichoice->box.y = WIN_HEIGHT - 100;
	multichoice->box.x_text = multichoice->box.x - 80;
	multichoice->box.y_text = multichoice->box.y + 17;
	ft_strlcpy(multichoice->box.description, "Difficulty", 11);
	ft_strlcpy(multichoice->box.font, FONT, ft_strlen(FONT));
	multichoice->box.mouse_press = multichoice_press_score;
	multichoice->box.mouse_release = NULL;
	obj = dict_new(MULTICHOICE, multichoice);
	if (!obj)
		return (free(multichoice), (void *)0);
	return (obj);
}
