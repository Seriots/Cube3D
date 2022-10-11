/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numinput_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:37:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 10:39:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include <X11/keysymdef.h>

int	numinput_keypress(KeySym key, t_game *game)
{
	t_numinput	*numinput;
	int			keyint;

	numinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288))
		delete_number(numinput);
	else if (key == XK_Return || key == XK_KP_Enter)
	{
		reset_key_event_num(game, numinput);
		*numinput->modified_value = numinput->red * 256 * 256
			+ numinput->green * 256 + numinput->blue;
	}
	else if ((key == XK_Left) && numinput->is_selected > 1)
		numinput->is_selected = numinput->is_selected - 1;
	else if ((key == XK_Right) && numinput->is_selected < 3)
		numinput->is_selected = numinput->is_selected + 1;
	else
	{
		keyint = get_number_from_key(key);
		if (keyint != -1)
			add_number(numinput, keyint);
	}
	return (0);
}

int	numinput_keyrelease(KeySym key, t_game *game)
{
	t_numinput	*numinput;

	numinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if (key == XK_Escape)
	{
		reset_key_event_num(game, numinput);
		edit_rgb(numinput);
	}
	return (0);
}

int	numinput_release(int button, int x, int y, t_game *game)
{
	t_numinput	*numinput;

	if (button != 1)
		return (0);
	numinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if (numinput->press_case == get_case_clicked(game, numinput, x, y))
	{
		if (numinput->is_selected == numinput->press_case)
			numinput->is_selected = 0;
		else
			numinput->is_selected = numinput->press_case;
		if (numinput->is_selected)
		{
			game->fcts.keypressed_fct = numinput_keypress;
			game->fcts.keyreleased_fct = numinput_keyrelease;
			clear_all_other_selected(game, numinput, game->menu.all_objects);
		}
		if (!numinput->is_selected)
			reset_key_event_num(game, numinput);
		if (!numinput->is_selected)
			edit_rgb(numinput);
	}
	game->fcts.mousereleased_fct = menu_mouse_release;
	return (0);
}

int	numinput_press(int button, int x, int y, t_game *game)
{
	t_numinput	*numinput;

	numinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if (button == 1)
	{
		numinput->press_case = get_case_clicked(game, numinput, x, y);
		if (numinput->press_case != 0)
			game->fcts.mousereleased_fct = numinput_release;
	}
	return (0);
}
