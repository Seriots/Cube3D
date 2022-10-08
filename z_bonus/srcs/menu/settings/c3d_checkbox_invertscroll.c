/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkbox_invertscroll.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:23:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	invertscroll_release(int button, int x, int y, t_game *game)
{
	t_checkbox	*checkbox;

	if (button == 1)
	{
		checkbox = dict_getelem_number(game->menu.all_objects, 15)->value;
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

int	invertscroll_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = invertscroll_release;
	return (0);
}

t_dict	*init_invertscroll_checkbox(t_game *game)
{
	t_checkbox	*checkbox;
	t_dict		*obj;

	checkbox = malloc(sizeof(t_checkbox));
	if (!checkbox)
		return (0);
	checkbox->box.x = CHECKBOX_START_X;
	checkbox->box.y = CHECKBOX_START_Y + MARGE;
	checkbox->modified_value = &game->settings.invert_scroll;
	checkbox->is_check = *checkbox->modified_value;
	checkbox->box.height = 20;
	checkbox->box.width = 20;
	checkbox->box.x_text = checkbox->box.x - 100;
	checkbox->box.y_text = checkbox->box.y + 15;
	ft_strlcpy(checkbox->box.description, "Invert scroll", 14);
	ft_strlcpy(checkbox->box.font, FONT, ft_strlen(FONT));
	checkbox->box.mouse_press = invertscroll_press;
	checkbox->box.mouse_release = NULL;
	obj = dict_new(CHECKBOX, checkbox);
	if (!obj)
		return (free(checkbox), (void *)0);
	return (obj);
}
