/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_slidebar_camspeedx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:37:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 16:29:57 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct_bonus.h"
#include "c3d_event_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_menu_bonus.h"

#include "ft.h"
#include "dict.h"

#include "mlx.h"

#include <stdio.h>

int	camspeedx_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = menu_mouse_release;
		game->fcts.mousemove_fct = menu_mouse_move;
	}
	return (0);
}

int	camspeedx_mouse_move(int x, int y, t_game *game)
{
	t_slidebar	*value;

	(void)y;
	value = dict_getelem_number(game->menu.all_objects, 16)->value;
	x = x - (WIN_WIDTH / 2 - MENU_WIDTH / 2);
	if (x < value->box.x)
		value->x = value->box.x;
	else if (x > value->box.x + value->box.width - value->width)
		value->x = value->box.width + value->box.x - value->width;
	else
		value->x = x;
	*(value->modified_value) = value->min + (value->x - value->box.x)
		* (value->max - value->min) / (value->box.width - value->width);
	return (0);
}

int	camspeedx_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = camspeedx_mouse_release;
		game->fcts.mousemove_fct = camspeedx_mouse_move;
		camspeedx_mouse_move(x, y, game);
	}		
	return (0);
}

void	camspeedx_init(t_slidebar *slidebar)
{
	slidebar->x = slidebar->box.x - slidebar->width + (*slidebar->modified_value - slidebar->min)
		* slidebar->box.width / (slidebar->max - slidebar->min);
	slidebar->y = slidebar->box.y
		- (slidebar->height - slidebar->box.height) / 2;
	slidebar->box.x_text = slidebar->box.x - 100;
	slidebar->box.y_text = slidebar->box.y + 10;
	ft_strlcpy(slidebar->box.description, "Sensibility X", 14);
	ft_strlcpy(slidebar->box.font, FONT, ft_strlen(FONT));
}

t_dict	*init_camspeedx_slidebar(t_game *game)
{
	t_slidebar	*slidebar;
	t_dict		*obj;

	slidebar = malloc(sizeof(t_slidebar));
	if (!slidebar)
		return (0);
	slidebar->box.x = SLIDEBAR_START_X;
	slidebar->box.y = SLIDEBAR_START_Y + 2 * MARGE;
	slidebar->box.width = 200;
	slidebar->box.height = 10;
	slidebar->min = 1;
	slidebar->max = 100;
	slidebar->height = 18;
	slidebar->width = 6;
	slidebar->modified_value = &game->settings.cam_sensibility_x;
	camspeedx_init(slidebar);
	slidebar->box.mouse_press = camspeedx_press;
	slidebar->box.mouse_release = NULL;
	obj = dict_new(SLIDEBAR, slidebar);
	if (!obj)
		return (free(slidebar), (void *)0);
	return (obj);
}
