/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textinput_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:55:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 17:54:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_init.h"

#include "ft.h"

int	textinput_keypress(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects,
			game->pick_obj)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288)
		&& textinput->size > 0)
		textinput->path[--textinput->size] = '\0';
	else if (key == XK_Return || key == XK_KP_Enter)
		event_enter_textinput(game, textinput);
	else if (key == XK_Shift_L || key == XK_Shift_R)
		textinput->shift += 1;
	else if (key == XK_Caps_Lock && textinput->caps_lock == 0)
		textinput->caps_lock = 2;
	else if (textinput->size < 255)
	{
		if (get_char_from_key(key, textinput->shift, textinput->caps_lock))
		{
			textinput->path[textinput->size] = get_char_from_key(key,
					textinput->shift, textinput->caps_lock);
			textinput->size += 1;
			textinput->start_display += 1;
			textinput->path[textinput->size] = '\0';
		}
	}
	return (0);
}

int	textinput_keyrelease(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects,
			game->pick_obj)->value;
	if (key == XK_Escape)
		reset_textinput(game, textinput);
	else if (key == XK_Shift_L || key == XK_Shift_R)
	{
		if (textinput->shift > 0)
			textinput->shift -= 1;
	}
	else if (key == XK_Caps_Lock && textinput->caps_lock != 0)
		textinput->caps_lock -= 1;
	return (0);
}

int	textinput_release(int button, int x, int y, t_game *game)
{
	t_textinput	*textinput;

	if (button != 1)
		return (0);
	textinput = dict_getelem_number(game->menu.all_objects,
			game->pick_obj)->value;
	if (release_cond_textinput(game, textinput, x, y))
	{
		textinput->is_selected = !textinput->is_selected;
		if (textinput->is_selected)
		{
			textinput->start_display = textinput->size;
			game->fcts.keypressed_fct = textinput_keypress;
			game->fcts.keyreleased_fct = textinput_keyrelease;
			clear_all_other_selected(game, textinput, game->menu.all_objects);
		}
		else
			reset_textinput(game, textinput);
	}
	game->fcts.mousereleased_fct = menu_mouse_release;
	return (0);
}

int	textinput_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = textinput_release;
	return (0);
}
