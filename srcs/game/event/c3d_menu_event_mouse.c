/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_event_mouse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:03:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 12:08:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"
#include "c3d_event.h"

#include "mlx.h"

#include <stdio.h>

int	check_all_objects_press(t_game *game, int x, int y)
{
	t_dict			*tmp;
	t_collide_box	*box;
	
	tmp = game->menu.all_objects;
	while (tmp)
	{
		box = tmp->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= box->x && x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= box->x + box->width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= box->y && y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= box->y + box->height)
		{
			if (box->mouse_press)
				box->mouse_press(1, x, y, game);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	check_all_objects_release(t_game *game, int x, int y)
{
	t_dict			*tmp;
	t_collide_box	*box;
	
	tmp = game->menu.all_objects;
	while (tmp)
	{
		box = tmp->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= box->x && x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= box->x + box->width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= box->y && y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= box->y + box->height)
		{
			if (box->mouse_release)
				box->mouse_release(1, x, y, game);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	menu_mouse_press(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	printf("Mouse pressed: %d\n", button);
	if (button == 1)
		check_all_objects_press(game, x, y);
	return (0);
}

int	menu_mouse_release(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	printf("Mouse released: %d\n", button);
	if (button == 3)
		close_window(game);
	if (button == 1)
		check_all_objects_release(game, x, y);
	return (0);
}

int	menu_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	(void)game;
	return (0);
}