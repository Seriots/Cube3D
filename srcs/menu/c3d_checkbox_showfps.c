/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_checkbox_showfps.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:11:14 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/05 13:12:48 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	showfps_release(int button, int x, int y, t_game *game)
{
	t_checkbox	*checkbox;

	if (button == 1)
	{
		checkbox = dict_getelem_number(game->menu.all_objects, 18)->value;
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

int	showfps_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = showfps_release;
	return (0);
}

t_dict	*init_showfps_checkbox(t_game *game)
{
	t_checkbox	*checkbox;
	t_dict		*obj;

	checkbox = malloc(sizeof(t_checkbox));
	if (!checkbox)
		return (0);
	checkbox->box.x = CHECKBOX_START_X;
	checkbox->box.y = CHECKBOX_START_Y + 2 * MARGE;
	checkbox->modified_value = &game->settings.show_fps;
	checkbox->is_check = *checkbox->modified_value;
	checkbox->box.height = 20;
	checkbox->box.width = 20;
	checkbox->box.x_text = checkbox->box.x - 100;
	checkbox->box.y_text = checkbox->box.y + 15;
	ft_strlcpy(checkbox->box.description, "Show FPS", 9);
	ft_strlcpy(checkbox->box.font, FONT, ft_strlen(FONT));
	checkbox->box.mouse_press = showfps_press;
	checkbox->box.mouse_release = NULL;
	obj = dict_new(CHECKBOX, checkbox);
	if (!obj)
		return (free(checkbox), (void *)0);
	return (obj);
}
