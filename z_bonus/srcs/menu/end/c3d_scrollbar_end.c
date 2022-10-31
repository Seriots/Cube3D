/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scrollbar_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:55:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:40:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "ft.h"
#include "dict.h"

#include "mlx.h"

int	scrollbar_mouse_release_end(int button, int x, int y, t_game *game)
{
	t_scrollbar	*value;

	(void)x;
	(void)y;
	if (button == 1)
	{
		value = (dict_getelem_key(game->end_menu.all_objects,
					SCROLLBAR2)->value);
		game->fcts.mousereleased_fct = end_mouse_release;
		game->fcts.mousemove_fct = end_mouse_move;
		value->is_selected = 0;
	}
	return (0);
}

int	scrollbar_mouse_move_end(int x, int y, t_game *game)
{
	t_dict		*bar;
	t_scrollbar	*value;
	float		percent_pos;

	(void)x;
	game->is_update = 1;
	bar = dict_getelem_key(game->end_menu.all_objects, SCROLLBAR2);
	value = bar->value;
	y = y - (WIN_HEIGHT / 2 - END_HEIGHT / 2);
	if (y - value->click_position < value->min)
		value->box.y = value->min;
	else if (y - value->click_position > value->max)
		value->box.y = value->max;
	else
		value->box.y = y - value->click_position;
	percent_pos = (float)(value->box.y - value->min)
		/ (float)(value->max - value->min);
	*value->modified_value = -(percent_pos * value->max_obj);
	return (0);
}

int	scrollbar_press_end(int button, int x, int y, t_game *game)
{
	t_scrollbar	*value;

	(void)x;
	(void)y;
	if (button == 1)
	{
		value = (dict_getelem_key(game->end_menu.all_objects,
					SCROLLBAR2)->value);
		value->is_selected = 1;
		value->click_position = y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
			- value->box.y;
		game->fcts.mousereleased_fct = scrollbar_mouse_release_end;
		game->fcts.mousemove_fct = scrollbar_mouse_move_end;
	}
	return (0);
}

int	set_height_end(t_game *game, int *max_obj)
{
	int		max;

	(void)game;
	max = 30 + (15 * MENU_HEIGHT / 100)
		+ (sizeof(t_stat) / sizeof(t_tagint) - 2) * END_STAT_MARGE;
	*max_obj = max - MENU_HEIGHT + (30 * MENU_HEIGHT / 100);
	if (*max_obj < 0)
		*max_obj = 0;
	if (max <= MENU_HEIGHT - (30 * MENU_HEIGHT / 100))
		return (0);
	return ((float)(MENU_HEIGHT - (30 * MENU_HEIGHT / 100) - 14)
		*((float)(MENU_HEIGHT - (30 * MENU_HEIGHT / 100) - 14)
		/ ((float)max)));
}

t_dict	*init_scrollbar_end(t_game *game)
{
	t_scrollbar	*scrollbar;
	t_dict		*obj;

	scrollbar = malloc(sizeof(t_scrollbar));
	if (!scrollbar)
		return (0);
	scrollbar->box.height = set_height_end(game, &scrollbar->max_obj);
	scrollbar->max = (MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
		- 7 - scrollbar->box.height;
	scrollbar->min = (15 * MENU_HEIGHT / 100) + 7;
	scrollbar->is_selected = 0;
	scrollbar->box.width = 12;
	scrollbar->box.x = END_WIDTH - 19;
	scrollbar->box.y = scrollbar->min;
	scrollbar->box.x_text = 0;
	scrollbar->box.y_text = 0;
	ft_strlcpy(scrollbar->box.font, FONT, ft_strlen(FONT));
	scrollbar->box.mouse_press = scrollbar_press_end;
	scrollbar->box.mouse_release = NULL;
	scrollbar->modified_value = &game->end_menu.scroll_amount;
	obj = dict_new(SCROLLBAR2, scrollbar);
	if (!obj)
		return (free(scrollbar), (void *)0);
	return (obj);
}
