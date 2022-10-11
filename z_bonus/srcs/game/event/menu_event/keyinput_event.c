/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyinput_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:32:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 10:34:23 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

int	keyinput_keypress(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	if (key > 32 && key < 127)
	{
		keyinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
		*keyinput->modified_value = key;
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
		update_key_color(game, &game->menu);
	}
	return (0);
}

int	keyinput_keyrelease(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if (key == XK_Escape)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
	}
	return (0);
}

int	keyinput_release(int button, int x, int y, t_game *game)
{
	t_keyinput	*keyinput;

	if (button != 1)
		return (0);
	keyinput = dict_getelem_number(game->menu.all_objects, game->pick_obj)->value;
	if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= keyinput->box.x
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= keyinput->box.x
		+ keyinput->box.width && y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		>= keyinput->box.y + game->menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= keyinput->box.y
		+ game->menu.scroll_amount + keyinput->box.height)
	{
		keyinput->is_selected = !keyinput->is_selected;
		if (keyinput->is_selected)
		{
			game->fcts.keypressed_fct = keyinput_keypress;
			game->fcts.keyreleased_fct = keyinput_keyrelease;
			clear_all_other_selected(game, keyinput, game->menu.all_objects);
		}
		if (!keyinput->is_selected)
			reset_key_event(game);
	}
	game->fcts.mousereleased_fct = menu_mouse_release;
	return (0);
}

int	keyinput_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = keyinput_release;
	return (0);
}
