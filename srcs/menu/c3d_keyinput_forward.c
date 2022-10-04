/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keyinput_forward.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:02:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 16:00:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	forward_keypress(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 4)->value;
	if (key > 32 && key < 127)
	{
		keyinput = dict_getelem_number(game->menu.all_objects, 4)->value;
		*keyinput->modified_value = key;
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
		update_key_color(game, &game->menu);
	}
	return (0);
}

int	forward_keyrelease(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 4)->value;
	if (key == XK_Escape)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
	}
	return (0);
}

int	forward_release(int button, int x, int y, t_game *game)
{
	t_keyinput	*keyinput;

	if (button == 1)
	{
		keyinput = dict_getelem_number(game->menu.all_objects, 4)->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= keyinput->box.x
			&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= keyinput->box.x + keyinput->box.width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= keyinput->box.y + game->menu.scroll_amount
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= keyinput->box.y + game->menu.scroll_amount + keyinput->box.height)
		{
			keyinput->is_selected = !keyinput->is_selected;
			if (keyinput->is_selected)
			{
				game->fcts.keypressed_fct = forward_keypress;
				game->fcts.keyreleased_fct = forward_keyrelease;
				clear_all_other_selected(game, keyinput);
			}
			else
			{
				game->fcts.keypressed_fct = menu_key_press;
				game->fcts.keyreleased_fct = menu_key_release;
			}
		}
		game->fcts.mousereleased_fct = menu_mouse_release;
	}
	return (0);
}

int	forward_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = forward_release;
	return (0);
}

t_dict	*init_forward_keyinput(t_game *game)
{
	t_keyinput	*keyinput;
	t_dict		*obj;

	(void)game;
	keyinput = malloc(sizeof(t_keyinput));
	if (!keyinput)
		return (0);
	keyinput->is_selected = 0;
	keyinput->box.height = 24;
	keyinput->box.width = 40;
	keyinput->box.x = 100;
	keyinput->box.y = 150;
	keyinput->box.x_text = keyinput->box.x - 80;
	keyinput->box.y_text = keyinput->box.y + 15;
	ft_strlcpy(keyinput->box.description, "Forward", 8);
	ft_strlcpy(keyinput->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	keyinput->box.mouse_press = forward_press;
	keyinput->box.mouse_release = NULL;
	keyinput->modified_value = &game->settings.forward;
	keyinput->color = get_key_color(game, &game->settings.forward);
	obj = dict_new(KEYINPUT, keyinput);
	if (!obj)
		return (free(keyinput), (void *)0);
	return (obj);
}
