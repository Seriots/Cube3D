/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_textinput_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:56:46 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:40:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "c3d_event.h"

#include "ft.h"
#include "mlx.h"

t_dict	*init_nameinput_end(t_game *game)
{
	t_nameinput	*nameinput;
	t_dict		*obj;

	nameinput = malloc(sizeof(t_nameinput));
	if (!nameinput)
		return (0);
	nameinput->box.height = 24;
	nameinput->box.width = 200;
	nameinput->box.x = 240;
	nameinput->box.y = 15 * MENU_HEIGHT / 100 + 20;
	nameinput->box.x_text = nameinput->box.x - 220;
	nameinput->box.y_text = nameinput->box.y + 15;
	ft_strlcpy(nameinput->box.description, "Name", 5);
	ft_strlcpy(nameinput->box.font, FONT, ft_strlen(FONT));
	nameinput->box.mouse_press = nameinput_press;
	nameinput->box.mouse_release = NULL;
	init_nameinput(game, nameinput);
	obj = dict_new(NAMEINPUT, nameinput);
	if (!obj)
		return (free(nameinput), (void *)0);
	return (obj);
}
