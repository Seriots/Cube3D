/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:09:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 20:31:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_menu.h"
#include "c3d_event.h"
#include "c3d_startscreen.h"

#include "dict.h"

int	check_one_obj_press(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	box = tmp->value;
	if (press_collide_cond(game, x, y, tmp))
	{
		if (box->mouse_press)
			return (1);
	}
	else if (press_scrollbar_cond(game, x, y, tmp))
	{
		if (box->mouse_press)
			return (1);
	}
	return (0);
}

int	check_one_obj_press_end(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	box = tmp->value;
	if (press_collide_cond_end(game, x, y, tmp))
	{
		if (box->mouse_press)
			return (1);
	}
	else if (press_scrollbar_cond_end(game, x, y, tmp))
	{
		if (box->mouse_press)
			return (1);
	}
	return (0);
}

int	validate_seed(t_game *game, t_seed *seed)
{
	*seed->modified_value = seed->tmp_value;
	seed->is_selected = 0;
	game->fcts.keypressed_fct = startscreen_key_press;
	game->fcts.keyreleased_fct = startscreen_key_release;
	return (0);
}

int	release_cond_nameinput(t_game *game, t_nameinput *textinput, int x, int y)
{
	if (x - (WIN_WIDTH / 2 - END_WIDTH / 2) >= textinput->box.x
		&& x - (WIN_WIDTH / 2 - END_WIDTH / 2)
		<= textinput->box.x + textinput->box.width
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
		>= textinput->box.y + game->end_menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
		<= textinput->box.y + game->end_menu.scroll_amount
		+ textinput->box.height)
		return (1);
	return (0);
}

int	release_cond_textinput_start(t_game *game, t_textinput *textinput,
	int x, int y)
{
	(void)game;
	if (x >= textinput->box.x
		&& x <= textinput->box.x + textinput->box.width
		&& y >= textinput->box.y
		&& y <= textinput->box.y + textinput->box.height)
		return (1);
	return (0);
}
