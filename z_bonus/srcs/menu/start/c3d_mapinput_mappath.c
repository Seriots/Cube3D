/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mapinput_mappath.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:52:49 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:41:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "c3d_startscreen.h"
#include "c3d_event.h"

#include "ft.h"
#include "mlx.h"

t_dict	*init_textinput_mappath(t_game *game)
{
	t_textinput	*textinput;
	t_dict		*obj;

	textinput = malloc(sizeof(t_textinput));
	if (!textinput)
		return (0);
	textinput->box.height = 24;
	textinput->box.width = 200;
	textinput->box.x = 100;
	textinput->box.y = WIN_HEIGHT - 100;
	textinput->box.x_text = textinput->box.x - 70;
	textinput->box.y_text = textinput->box.y + 15;
	ft_strlcpy(textinput->box.description, "Map Path", 9);
	ft_strlcpy(textinput->box.font, FONT, ft_strlen(FONT));
	textinput->box.mouse_press = mapinput_press;
	textinput->box.mouse_release = NULL;
	textinput->modified_path = &game->settings.map_path;
	init_textinput(textinput);
	obj = dict_new(TEXTINPUT2, textinput);
	if (!obj)
		return (free(textinput), (void *)0);
	return (obj);
}
