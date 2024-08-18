/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkbox_invertmouse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:14:42 by lgiband           #+#    #+#             */
/*   Updated: 2024/08/18 12:39:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_event.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

t_dict	*init_invertmouse_checkbox(t_game *game)
{
	t_checkbox	*checkbox;
	t_dict		*obj;

	checkbox = malloc(sizeof(t_checkbox));
	if (!checkbox)
		return (0);
	checkbox->box.x = CHECKBOX_START_X;
	checkbox->box.y = CHECKBOX_START_Y + 4 * MARGE;
	check_value_checkbox(&game->settings.invert_mouse);
	checkbox->modified_value = &game->settings.invert_mouse;
	checkbox->is_check = *checkbox->modified_value;
	checkbox->box.height = 20;
	checkbox->box.width = 20;
	checkbox->box.x_text = checkbox->box.x - 100;
	checkbox->box.y_text = checkbox->box.y + 15;
	ft_strlcpy(checkbox->box.description, "Invert Mouse", 13);
	ft_strlcpy(checkbox->box.font, FONT, ft_strlen(FONT));
	checkbox->box.mouse_press = checkbox_press;
	checkbox->box.mouse_release = NULL;
	obj = dict_new(CHECKBOX, checkbox);
	if (!obj)
		return (free(checkbox), (void *)0);
	return (obj);
}
