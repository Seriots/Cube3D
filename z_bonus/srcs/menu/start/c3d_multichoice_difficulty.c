/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_multichoice_difficulty.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:43:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:15:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

#include <stdio.h>

int	multichoice_press(int button, int x, int y, t_game *game)
{
	t_multichoice	*multichoice;

	(void)y;
	if (button == 1)
	{
		multichoice
			= dict_getelem_number(game->start_menu.all_objects, 0)->value;
		if (x <= multichoice->box.x + multichoice->box.width / 8)
			multichoice->current--;
		else if (x >= multichoice->box.x + 7 * (multichoice->box.width / 8))
			multichoice->current++;
		if (multichoice->current < 0)
			multichoice->current = multichoice->max;
		else if (multichoice->current > multichoice->max)
			multichoice->current = 0;
		*multichoice->modified_value = multichoice->current;
	}
	return (0);
}

void	set_multichoice_difficulty(t_game *game, t_multichoice *multichoice)
{
	multichoice->min = 0;
	multichoice->max = 2;
	ft_strlcpy(multichoice->all_values[0], "EASY", 5);
	ft_strlcpy(multichoice->all_values[1], "MEDIUM", 7);
	ft_strlcpy(multichoice->all_values[2], "HARD", 5);
	multichoice->modified_value = &game->settings.difficulty;
	multichoice->current = *multichoice->modified_value;
}

t_dict	*init_multichoice_difficulty(t_game *game)
{
	t_multichoice	*multichoice;
	t_dict			*obj;

	multichoice = malloc(sizeof(t_multichoice));
	if (!multichoice)
		return (0);
	set_multichoice_difficulty(game, multichoice);
	multichoice->box.height = 24;
	multichoice->box.width = 200;
	multichoice->box.x = WIN_WIDTH / 2 - multichoice->box.width / 2;
	multichoice->box.y = WIN_HEIGHT - 100;
	multichoice->box.x_text = multichoice->box.x - 80;
	multichoice->box.y_text = multichoice->box.y + 17;
	ft_strlcpy(multichoice->box.description, "Difficulty", 11);
	ft_strlcpy(multichoice->box.font, FONT, ft_strlen(FONT));
	multichoice->box.mouse_press = multichoice_press;
	multichoice->box.mouse_release = NULL;
	obj = dict_new(MULTICHOICE, multichoice);
	if (!obj)
		return (free(multichoice), (void *)0);
	return (obj);
}
