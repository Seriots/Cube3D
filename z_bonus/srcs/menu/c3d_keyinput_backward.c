/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keyinput_backward.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:59:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

int	backward_keypress(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 8)->value;
	if (key > 32 && key < 127)
	{
		keyinput = dict_getelem_number(game->menu.all_objects, 8)->value;
		*keyinput->modified_value = key;
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
		update_key_color(game, &game->menu);
	}
	return (0);
}

int	backward_keyrelease(KeySym key, t_game *game)
{
	t_keyinput	*keyinput;

	keyinput = dict_getelem_number(game->menu.all_objects, 8)->value;
	if (key == XK_Escape)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		game->fcts.mousereleased_fct = menu_mouse_release;
		keyinput->is_selected = 0;
	}
	return (0);
}

int	backward_release(int button, int x, int y, t_game *game)
{
	t_keyinput	*keyinput;

	if (button != 1)
		return (0);
	keyinput = dict_getelem_number(game->menu.all_objects, 8)->value;
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
			game->fcts.keypressed_fct = backward_keypress;
			game->fcts.keyreleased_fct = backward_keyrelease;
			clear_all_other_selected(game, keyinput);
		}
		if (!keyinput->is_selected)
			reset_key_event(game);
	}
	game->fcts.mousereleased_fct = menu_mouse_release;
	return (0);
}

int	backward_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = backward_release;
	return (0);
}

t_dict	*init_backward_keyinput(t_game *game)
{
	t_keyinput	*keyinput;
	t_dict		*obj;

	keyinput = malloc(sizeof(t_keyinput));
	if (!keyinput)
		return (0);
	keyinput->is_selected = 0;
	keyinput->box.height = 24;
	keyinput->box.width = 40;
	keyinput->box.x = KEYINPUT_START_X;
	keyinput->box.y = KEYINPUT_START_Y + MARGE;
	keyinput->box.x_text = keyinput->box.x - 100;
	keyinput->box.y_text = keyinput->box.y + 15;
	ft_strlcpy(keyinput->box.description, "Backward", 9);
	ft_strlcpy(keyinput->box.font, FONT, ft_strlen(FONT));
	keyinput->box.mouse_press = backward_press;
	keyinput->box.mouse_release = NULL;
	keyinput->modified_value = &game->settings.backward;
	keyinput->color = get_key_color(game, &game->settings.backward);
	obj = dict_new(KEYINPUT, keyinput);
	if (!obj)
		return (free(keyinput), (void *)0);
	return (obj);
}
