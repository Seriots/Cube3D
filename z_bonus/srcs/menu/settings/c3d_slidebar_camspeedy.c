/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_slidebar_camspeedy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:48:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:40:50 by lgiband          ###   ########.fr       */
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

void	camspeedy_init(t_slidebar *slidebar)
{
	slidebar->x = slidebar->box.x - slidebar->width
		+ (*slidebar->modified_value - slidebar->min)
		* slidebar->box.width / (slidebar->max - slidebar->min);
	slidebar->y = slidebar->box.y
		- (slidebar->height - slidebar->box.height) / 2;
	slidebar->box.x_text = slidebar->box.x - 100;
	slidebar->box.y_text = slidebar->box.y + 10;
	ft_strlcpy(slidebar->box.description, "Sensibility Y", 14);
	ft_strlcpy(slidebar->box.font, FONT, ft_strlen(FONT));
}

t_dict	*init_camspeedy_slidebar(t_game *game)
{
	t_slidebar	*slidebar;
	t_dict		*obj;

	slidebar = malloc(sizeof(t_slidebar));
	if (!slidebar)
		return (0);
	slidebar->box.x = SLIDEBAR_START_X;
	slidebar->box.y = SLIDEBAR_START_Y + 3 * MARGE;
	slidebar->box.width = 200;
	slidebar->box.height = 18;
	slidebar->min = 1;
	slidebar->max = 100;
	slidebar->height = 18;
	slidebar->width = 6;
	check_value_slidebar(&game->settings.cam_sensibility_y,
		slidebar->min, slidebar->max);
	slidebar->modified_value = &game->settings.cam_sensibility_y;
	camspeedy_init(slidebar);
	slidebar->box.mouse_press = slidebar_press;
	slidebar->box.mouse_release = NULL;
	obj = dict_new(SLIDEBAR, slidebar);
	if (!obj)
		return (free(slidebar), (void *)0);
	return (obj);
}
