/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_slidebar_camspeedy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:48:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:10 by lgiband          ###   ########.fr       */
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

int	camspeedy_mouse_release(int button, int x, int y, t_game *game)
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

int	camspeedy_mouse_move(int x, int y, t_game *game)
{
	t_slidebar	*value;

	(void)y;
	value = dict_getelem_number(game->menu.all_objects, 17)->value;
	x = x - (WIN_WIDTH / 2 - MENU_WIDTH / 2);
	if (x < value->x)
		value->box.x = value->x;
	else if (x > value->x + value->width - value->box.width)
		value->box.x = value->width + value->x - value->box.width;
	else
		value->box.x = x;
	*(value->modified_value) = value->min + (value->box.x - value->x)
		* (value->max - value->min) / (value->width - value->box.width);
	return (0);
}

int	camspeedy_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = camspeedy_mouse_release;
		game->fcts.mousemove_fct = camspeedy_mouse_move;
	}
	return (0);
}

void	camspeedy_init(t_slidebar *slidebar)
{
	slidebar->box.x = slidebar->x + (*slidebar->modified_value - slidebar->min)
		* slidebar->width / (slidebar->max - slidebar->min);
	slidebar->box.y = slidebar->y
		- (slidebar->box.height - slidebar->height) / 2;
	slidebar->box.x_text = slidebar->x - 100;
	slidebar->box.y_text = slidebar->y + 10;
	ft_strlcpy(slidebar->box.description, "Camera speed Y", 15);
	ft_strlcpy(slidebar->box.font, FONT, ft_strlen(FONT));
}

t_dict	*init_camspeedy_slidebar(t_game *game)
{
	t_slidebar	*slidebar;
	t_dict		*obj;

	slidebar = malloc(sizeof(t_slidebar));
	if (!slidebar)
		return (0);
	slidebar->x = SLIDEBAR_START_X;
	slidebar->y = SLIDEBAR_START_Y + 3 * MARGE;
	slidebar->width = 200;
	slidebar->height = 10;
	slidebar->min = 1;
	slidebar->max = 100;
	slidebar->box.height = 18;
	slidebar->box.width = 6;
	slidebar->modified_value = &game->settings.cam_sensibility_y;
	camspeedy_init(slidebar);
	slidebar->box.mouse_press = camspeedy_press;
	slidebar->box.mouse_release = NULL;
	obj = dict_new(SLIDEBAR, slidebar);
	if (!obj)
		return (free(slidebar), (void *)0);
	return (obj);
}
