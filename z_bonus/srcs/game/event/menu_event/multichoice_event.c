/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichoice_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:06:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 21:40:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

int	multichoice_press(int button, int x, int y, t_game *game)
{
	t_multichoice	*multichoice;

	(void)y;
	if (button == 1)
	{
		multichoice = dict_getelem_number(game->start_menu.all_objects,
				game->pick_obj)->value;
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
