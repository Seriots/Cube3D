/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkbox_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:50:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 11:45:57 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

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
			&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= checkbox->box.x + checkbox->box.width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= checkbox->box.y
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= checkbox->box.y + checkbox->box.height)
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

	(void)game;
	checkbox = malloc(sizeof(t_checkbox));
	if (!checkbox)
		return (0);
	checkbox->is_check = game->settings.color;
	checkbox->box.height = 20;
	checkbox->box.width = 20;
	checkbox->box.x = 100; 
	checkbox->box.y = 100;
	checkbox->box.x_text = checkbox->box.x - 80;
	checkbox->box.y_text = checkbox->box.x + 15;
	ft_strlcpy(checkbox->box.description, "Color", 6);
	ft_strlcpy(checkbox->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	checkbox->box.mouse_press = color_press;
	checkbox->box.mouse_release = NULL;
	checkbox->modified_value = &game->settings.color;
	obj = dict_new(CHECKBOX, checkbox);
	if (!obj)
		return (free(checkbox), (void *)0);
	return (obj);
}