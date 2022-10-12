/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_keyinput_slot8.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:57:43 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 16:57:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_event.h"

#include "dict.h"
#include "ft.h"

#include <stdlib.h>

t_dict	*init_slot8_keyinput(t_game *game)
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
	keyinput->box.y = KEYINPUT_START_Y + 13 * MARGE;
	keyinput->box.x_text = keyinput->box.x - 100;
	keyinput->box.y_text = keyinput->box.y + 15;
	ft_strlcpy(keyinput->box.description, "Slot8", 6);
	ft_strlcpy(keyinput->box.font, FONT, ft_strlen(FONT));
	keyinput->box.mouse_press = keyinput_press;
	keyinput->box.mouse_release = NULL;
	check_value_keyinput(&game->settings.slot8, XK_8);
	keyinput->modified_value = &game->settings.slot8;
	keyinput->color = get_key_color(game, keyinput->modified_value);
	obj = dict_new(KEYINPUT, keyinput);
	if (!obj)
		return (free(keyinput), (void *)0);
	return (obj);
}
