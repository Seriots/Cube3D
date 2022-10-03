/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keyinput_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:13:44 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 13:29:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	left_release(int button, int x, int y, t_game *game)
{
	t_keyinput	*keyinput;

	if (button == 1)
	{
		keyinput = dict_getelem_number(game->menu.all_objects, 5)->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= keyinput->box.x
			&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= keyinput->box.x + keyinput->box.width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= keyinput->box.y
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= keyinput->box.y + keyinput->box.height)
		{
			keyinput->is_selected = !keyinput->is_selected;
			if (keyinput->is_selected)
				clear_all_other_selected(game, keyinput);
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

int	left_keypress(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 5)->value;
	if (key > 32 && key < 127)
	{
		*keyinput->modified_value = key;
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
		update_key_color(game, &game->menu);
	}
	return (0);
}

int	left_keyrelease(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 5)->value;
	if (key == XK_Escape)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
	}
	return (0);
}

int	left_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = left_release;
		game->fcts.keypressed_fct = left_keypress;
		game->fcts.keyreleased_fct = left_keyrelease;
	}
	return (0);
}

t_dict	*init_left_keyinput(t_game *game)
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
	keyinput->box.y = 200;
	keyinput->box.x_text = keyinput->box.x - 80;
	keyinput->box.y_text = keyinput->box.y + 15;
	ft_strlcpy(keyinput->box.description, "Left", 5);
	ft_strlcpy(keyinput->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	keyinput->box.mouse_press = left_press;
	keyinput->box.mouse_release = NULL;
	keyinput->modified_value = &game->settings.left;
	keyinput->color = get_key_color(game, &game->settings.left);
	obj = dict_new(KEYINPUT, keyinput);
	if (!obj)
		return (free(keyinput), (void *)0);
	return (obj);
}
