/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkbox_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:25:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 10:28:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

int	checkbox_release(int button, int x, int y, t_game *game)
{
	t_checkbox	*checkbox;

	if (button == 1)
	{
		checkbox = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= checkbox->box.x
			&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2)
			<= checkbox->box.x + checkbox->box.width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
			>= checkbox->box.y + game->menu.scroll_amount
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= checkbox->box.y
			+ checkbox->box.height + game->menu.scroll_amount)
		{
			*(checkbox->modified_value) = !(*(checkbox->modified_value));
			checkbox->is_check = !checkbox->is_check;
		}
		game->fcts.mousereleased_fct = menu_mouse_release;
	}
	return (0);
}

int	checkbox_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = checkbox_release;
	return (0);
}
