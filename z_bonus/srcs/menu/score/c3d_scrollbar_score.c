/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scrollbar_score.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:55:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 11:02:21 by lgiband          ###   ########.fr       */
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

#include <stdio.h>

int	scrollbar_mouse_release_score(int button, int x, int y, t_game *game)
{
	t_scrollbar	*value;

	(void)x;
	(void)y;
	if (button == 1)
	{
		value = (dict_getelem_key(game->score_menu.all_objects,
					SCROLLBAR3)->value);
		game->fcts.mousereleased_fct = scorescreen_mouse_release;
		game->fcts.mousemove_fct = scorescreen_mouse_move;
		value->is_selected = 0;
	}
	return (0);
}

int	scrollbar_mouse_move_score(int x, int y, t_game *game)
{
	t_dict		*bar;
	t_scrollbar	*value;
	float		percent_pos;

	(void)x;
	bar = dict_getelem_key(game->score_menu.all_objects, SCROLLBAR3);
	value = bar->value;
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

int	scrollbar_press_score(int button, int x, int y, t_game *game)
{
	t_scrollbar	*value;

	(void)x;
	(void)y;
	if (button == 1)
	{
		value = (dict_getelem_key(game->score_menu.all_objects,
					SCROLLBAR3)->value);
		value->is_selected = 1;
		value->click_position = y - value->box.y;
		game->fcts.mousereleased_fct = scrollbar_mouse_release_score;
		game->fcts.mousemove_fct = scrollbar_mouse_move_score;
	}
	return (0);
}

int	set_height_score(t_game *game, int *max_obj, int size)
{
	int		max;

	(void)game;
	max = 60 + size * SCORE_MARGE;
	if (max >= 600 && max < 660)
		max = 660;
	*max_obj = max - 594;
	if (*max_obj < 0)
		*max_obj = 0;
	if (max <= 594)
		return (0);
	return ((float)(594 * 594) / (float)max);
}

t_dict	*init_scrollbar_score(t_game *game)
{
	t_scrollbar	*scrollbar;
	t_dict		*obj;

	scrollbar = malloc(sizeof(t_scrollbar));
	if (!scrollbar)
		return (0);
	scrollbar->box.height = 0;
	scrollbar->max = 594;
	scrollbar->min = 57;
	scrollbar->max_obj = 0;
	scrollbar->is_selected = 0;
	scrollbar->box.width = 18;
	scrollbar->box.x = WIN_WIDTH / 2 + SCOREMENU_WIDTH / 2 - 24;
	scrollbar->box.y = scrollbar->min;
	scrollbar->box.x_text = 0;
	scrollbar->box.y_text = 0;
	ft_strlcpy(scrollbar->box.font, FONT, ft_strlen(FONT));
	scrollbar->box.mouse_press = scrollbar_press_score;
	scrollbar->box.mouse_release = NULL;
	scrollbar->modified_value = &game->score_menu.scroll_amount;
	obj = dict_new(SCROLLBAR3, scrollbar);
	if (!obj)
		return (free(scrollbar), (void *)0);
	return (obj);
}
