/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_numinput_ceil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:30:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:40:36 by lgiband          ###   ########.fr       */
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

t_dict	*init_numinput_ceil(t_game *game)
{
	t_numinput	*numinput;
	t_dict		*obj;

	numinput = malloc(sizeof(t_numinput));
	if (!numinput)
		return (0);
	numinput->box.height = 24;
	numinput->box.width = 200;
	numinput->box.x = NUMINPUT_START_X;
	numinput->box.y = NUMINPUT_START_Y;
	numinput->box.x_text = numinput->box.x - 100;
	numinput->box.y_text = numinput->box.y + 16;
	ft_strlcpy(numinput->box.font, FONT, ft_strlen(FONT));
	ft_strlcpy(numinput->box.description, "Ceil Color", 11);
	numinput->box.mouse_press = numinput_press;
	numinput->box.mouse_release = NULL;
	numinput->is_selected = 0;
	numinput->modified_value = &game->map.c;
	edit_rgb(numinput);
	obj = dict_new(NUMINPUT, numinput);
	if (!obj)
		return (free(numinput), (void *)0);
	return (obj);
}
