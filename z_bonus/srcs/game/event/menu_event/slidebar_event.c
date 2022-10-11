/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slidebar_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:41:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 13:17:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

int	slidebar_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = menu_mouse_release;
		game->fcts.mousemove_fct = menu_mouse_move;
	}
	return (0);
}

int	slidebar_mouse_move(int x, int y, t_game *game)
{
	t_slidebar	*value;

	(void)y;
	value = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	x = x - (WIN_WIDTH / 2 - MENU_WIDTH / 2);
	if (x < value->box.x)
		value->x = value->box.x;
	else if (x > value->box.x + value->box.width - value->width)
		value->x = value->box.width + value->box.x - value->width;
	else
		value->x = x;
	*(value->modified_value) = value->min + (value->x - value->box.x)
		* (value->max - value->min) / (value->box.width - value->width);
	return (0);
}

int	slidebar_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = slidebar_mouse_release;
		game->fcts.mousemove_fct = slidebar_mouse_move;
		slidebar_mouse_move(x, y, game);
	}		
	return (0);
}

int	check_value_slidebar(float *value, int min, int max)
{
	if (*value < min)
		*value = min;
	else if (*value > max)
		*value = max;
	return (0);
}
