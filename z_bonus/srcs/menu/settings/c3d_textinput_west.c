/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_textinput_west.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:18:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:02:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

int	west_keypress(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects, 12)->value;
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

int	west_keyrelease(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects, 12)->value;
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

int	west_release(int button, int x, int y, t_game *game)
{
	t_textinput	*textinput;

	if (button != 1)
		return (0);
	textinput = dict_getelem_number(game->menu.all_objects, 12)->value;
	if (release_cond_textinput(game, textinput, x, y))
	{
		textinput->is_selected = !textinput->is_selected;
		if (textinput->is_selected)
		{
			textinput->start_display = textinput->size;
			game->fcts.keypressed_fct = west_keypress;
			game->fcts.keyreleased_fct = west_keyrelease;
			clear_all_other_selected(game, textinput, game->menu.all_objects);
		}
		else
			reset_textinput(game, textinput);
	}
	game->fcts.mousereleased_fct = menu_mouse_release;
	return (0);
}

int	west_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = west_release;
	return (0);
}

t_dict	*init_textinput_west(t_game *game)
{
	t_textinput	*textinput;
	t_dict		*obj;

	textinput = malloc(sizeof(t_textinput));
	if (!textinput)
		return (0);
	textinput->box.height = 24;
	textinput->box.width = 200;
	textinput->box.x = TEXTINPUT_START_X;
	textinput->box.y = TEXTINPUT_START_Y + 3 * MARGE;
	textinput->box.x_text = textinput->box.x - 100;
	textinput->box.y_text = textinput->box.y + 15;
	ft_strlcpy(textinput->box.description, "West path", 10);
	ft_strlcpy(textinput->box.font, FONT, ft_strlen(FONT));
	textinput->box.mouse_press = west_press;
	textinput->box.mouse_release = NULL;
	textinput->modified_value = &game->all_img.we;
	textinput->modified_path = &game->map.we;
	init_textinput(textinput);
	obj = dict_new(TEXTINPUT, textinput);
	if (!obj)
		return (free(textinput), (void *)0);
	return (obj);
}
