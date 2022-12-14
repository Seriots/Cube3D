/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:36:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 20:28:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"
#include "c3d_utils.h"

#include "mlx.h"
#include "ft.h"

#include <stdlib.h>

int	event_enter_textinput(t_game *game, t_textinput *textinput)
{
	load_path(game, textinput, textinput->modified_path);
	game->fcts.keypressed_fct = menu_key_press;
	game->fcts.keyreleased_fct = menu_key_release;
	textinput->is_selected = 0;
	textinput->start_display = 0;
	return (0);
}

int	event_enter_textinput_start(t_game *game, t_textinput *textinput)
{
	char	*path;

	game->fcts.keypressed_fct = startscreen_key_press;
	game->fcts.keyreleased_fct = startscreen_key_release;
	textinput->is_selected = 0;
	textinput->start_display = 0;
	if (ft_strlen(textinput->path) == 0)
	{
		free(*textinput->modified_path);
		*textinput->modified_path = 0;
		return (0);
	}
	path = ft_strdup(textinput->path);
	if (!path)
	{
		if (!*textinput->modified_path)
			return (0);
		ft_strlcpy(textinput->path, *textinput->modified_path, 256);
		set_error_value(&game->menu, 10);
		return (0);
	}
	free(*textinput->modified_path);
	*textinput->modified_path = path;
	return (0);
}

int	scroll_up(t_game *game, t_menu *menu, char *tag)
{
	t_scrollbar	*scrollbar;
	float		percent_pos;
	int			y;

	scrollbar = dict_getelem_key(menu->all_objects, tag)->value;
	y = scrollbar->box.y - (game->settings.scroll_speed * scrollbar->max / 100);
	if (y < scrollbar->min)
		scrollbar->box.y = scrollbar->min;
	else if (y > scrollbar->max)
		scrollbar->box.y = scrollbar->max;
	else
		scrollbar->box.y = y;
	percent_pos = (float)(scrollbar->box.y - scrollbar->min)
		/ (float)(scrollbar->max - scrollbar->min);
	*scrollbar->modified_value = -(percent_pos * scrollbar->max_obj);
	return (0);
}

int	scroll_down(t_game *game, t_menu *menu, char *tag)
{
	t_scrollbar	*scrollbar;
	float		percent_pos;
	int			y;

	scrollbar = dict_getelem_key(menu->all_objects, tag)->value;
	y = scrollbar->box.y + (game->settings.scroll_speed * scrollbar->max / 100);
	if (y < scrollbar->min)
		scrollbar->box.y = scrollbar->min;
	else if (y > scrollbar->max)
		scrollbar->box.y = scrollbar->max;
	else
		scrollbar->box.y = y;
	percent_pos = (float)(scrollbar->box.y - scrollbar->min)
		/ (float)(scrollbar->max - scrollbar->min);
	*scrollbar->modified_value = -(percent_pos * scrollbar->max_obj);
	return (0);
}

int	add_number_seed(t_seed *seed, int keyint)
{
	if (seed->tmp_value * 10 + keyint <= 9999999999)
		seed->tmp_value = seed->tmp_value * 10 + keyint;
	return (0);
}
