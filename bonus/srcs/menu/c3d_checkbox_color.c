/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkbox_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:50:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_menu_bonus.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	color_release(int button, int x, int y, t_game *game)
{
	t_checkbox	*checkbox;

	if (button == 1)
	{
		checkbox = dict_getelem_number(game->menu.all_objects, 3)->value;
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

int	color_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = color_release;
	return (0);
}

t_dict	*init_color_checkbox(t_game *game)
{
	t_checkbox	*checkbox;
	t_dict		*obj;

	checkbox = malloc(sizeof(t_checkbox));
	if (!checkbox)
		return (0);
	checkbox->box.x = CHECKBOX_START_X;
	checkbox->box.y = CHECKBOX_START_Y;
	checkbox->modified_value = &game->settings.color;
	checkbox->is_check = *checkbox->modified_value;
	checkbox->box.height = 20;
	checkbox->box.width = 20;
	checkbox->box.x_text = checkbox->box.x - 100;
	checkbox->box.y_text = checkbox->box.y + 15;
	ft_strlcpy(checkbox->box.description, "Color", 6);
	ft_strlcpy(checkbox->box.font, FONT, ft_strlen(FONT));
	checkbox->box.mouse_press = color_press;
	checkbox->box.mouse_release = NULL;
	obj = dict_new(CHECKBOX, checkbox);
	if (!obj)
		return (free(checkbox), (void *)0);
	return (obj);
}
