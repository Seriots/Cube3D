/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nameinput_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:54:25 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 17:55:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_init.h"

#include "ft.h"

int	valid_name_textinput(t_game *game, t_nameinput *textinput)
{
	ft_strlcpy(game->settings.name, textinput->path, 20);
	game->fcts.keypressed_fct = end_key_press;
	game->fcts.keyreleased_fct = end_key_release;
	textinput->is_selected = 0;
	textinput->start_display = 0;
	save_settings(game);
	return (0);
}

int	nameinput_keypress(KeySym key, t_game *game)
{
	t_nameinput	*textinput;

	textinput = dict_getelem_number(game->end_menu.all_objects,
			game->pick_obj)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288)
		&& textinput->size > 0)
		textinput->path[--textinput->size] = '\0';
	else if (key == XK_Return || key == XK_KP_Enter)
		valid_name_textinput(game, textinput);
	else if (key == XK_Shift_L || key == XK_Shift_R)
		textinput->shift += 1;
	else if (key == XK_Caps_Lock && textinput->caps_lock == 0)
		textinput->caps_lock = 2;
	else if (textinput->size < 20)
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

int	nameinput_keyrelease(KeySym key, t_game *game)
{
	t_nameinput	*textinput;

	textinput = dict_getelem_number(game->end_menu.all_objects,
			game->pick_obj)->value;
	if (key == XK_Escape)
		valid_name_textinput(game, textinput);
	else if (key == XK_Shift_L || key == XK_Shift_R)
	{
		if (textinput->shift > 0)
			textinput->shift -= 1;
	}
	else if (key == XK_Caps_Lock && textinput->caps_lock != 0)
		textinput->caps_lock -= 1;
	return (0);
}

int	nameinput_release(int button, int x, int y, t_game *game)
{
	t_nameinput	*textinput;

	if (button != 1)
		return (0);
	textinput = dict_getelem_number(game->end_menu.all_objects,
			game->pick_obj)->value;
	if (release_cond_nameinput(game, textinput, x, y))
	{
		textinput->is_selected = !textinput->is_selected;
		if (textinput->is_selected)
		{
			textinput->start_display = textinput->size;
			game->fcts.keypressed_fct = nameinput_keypress;
			game->fcts.keyreleased_fct = nameinput_keyrelease;
			clear_all_other_selected(game, textinput,
				game->end_menu.all_objects);
		}
		else
			valid_name_textinput(game, textinput);
	}
	game->fcts.mousereleased_fct = end_mouse_release;
	return (0);
}

int	nameinput_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = nameinput_release;
	return (0);
}
