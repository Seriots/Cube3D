/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_slidebar_fps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:00:25 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 10:46:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_event.h"

#include "ft.h"
#include "dict.h"

#include "mlx.h"

#include <stdio.h>

void	fps_init(t_slidebar *slidebar)
{
	slidebar->x = slidebar->box.x - slidebar->width
		+ (*slidebar->modified_value - slidebar->min)
		* slidebar->box.width / (slidebar->max - slidebar->min);
	slidebar->y = slidebar->box.y
		- (slidebar->height - slidebar->box.height) / 2;
	slidebar->box.x_text = slidebar->box.x - 100;
	slidebar->box.y_text = slidebar->box.y + 10;
	ft_strlcpy(slidebar->box.description, "Fps", 4);
	ft_strlcpy(slidebar->box.font, FONT, ft_strlen(FONT));
}

t_dict	*init_fps_slidebar(t_game *game)
{
	t_slidebar	*slidebar;
	t_dict		*obj;

	slidebar = malloc(sizeof(t_slidebar));
	if (!slidebar)
		return (0);
	slidebar->box.x = SLIDEBAR_START_X;
	slidebar->box.y = SLIDEBAR_START_Y + 5 * MARGE;
	slidebar->box.width = 200;
	slidebar->box.height = 18;
	slidebar->min = 10;
	slidebar->max = 120;
	slidebar->height = 18;
	slidebar->width = 6;
	slidebar->modified_value = &game->settings.fps;
	fps_init(slidebar);
	slidebar->box.mouse_press = slidebar_press;
	slidebar->box.mouse_release = NULL;
	obj = dict_new(SLIDEBAR, slidebar);
	if (!obj)
		return (free(slidebar), (void *)0);
	return (obj);
}
