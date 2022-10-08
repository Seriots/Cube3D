/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_slidebar_scrollspeed.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:16:18 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "ft.h"
#include "dict.h"

#include "mlx.h"

#include <stdio.h>

int	scrollspeed_mouse_release(int button, int x, int y, t_game *game)
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

int	scrollspeed_mouse_move(int x, int y, t_game *game)
{
	t_slidebar	*value;

	(void)y;
	value = dict_getelem_number(game->menu.all_objects, 14)->value;
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

int	scrollspeed_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		game->fcts.mousereleased_fct = scrollspeed_mouse_release;
		game->fcts.mousemove_fct = scrollspeed_mouse_move;
		scrollspeed_mouse_move(x, y, game);
	}
	return (0);
}

void	scrollspeed_init(t_slidebar *slidebar)
{
	slidebar->x = slidebar->box.x - slidebar->width + (*slidebar->modified_value - slidebar->min)
		* slidebar->box.width / (slidebar->max - slidebar->min);
	slidebar->y = slidebar->box.y
		- (slidebar->height - slidebar->box.height) / 2;
	slidebar->box.x_text = slidebar->box.x - 100;
	slidebar->box.y_text = slidebar->box.y + 10;
	ft_strlcpy(slidebar->box.description, "Scrollspeed", 12);
	ft_strlcpy(slidebar->box.font, FONT, ft_strlen(FONT));
}

t_dict	*init_scrollspeed_slidebar(t_game *game)
{
	t_slidebar	*slidebar;
	t_dict		*obj;

	slidebar = malloc(sizeof(t_slidebar));
	if (!slidebar)
		return (0);
	slidebar->box.x = SLIDEBAR_START_X;
	slidebar->box.y = SLIDEBAR_START_Y + 1 * MARGE;
	slidebar->box.width = 200;
	slidebar->box.height = 10;
	slidebar->min = 1;
	slidebar->max = 20;
	slidebar->height = 18;
	slidebar->width = 6;
	slidebar->modified_value = &game->settings.scroll_speed;
	scrollspeed_init(slidebar);
	slidebar->box.mouse_press = scrollspeed_press;
	slidebar->box.mouse_release = NULL;
	obj = dict_new(SLIDEBAR, slidebar);
	if (!obj)
		return (free(slidebar), (void *)0);
	return (obj);
}