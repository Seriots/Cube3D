/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen_event_mouse.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:46:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "ft.h"
#include "mlx.h"

int	check_all_objects_press_start(t_game *game, int x, int y, t_dict *dict)
{
	t_dict			*tmp;
	t_collide_box	*box;
	int				i;

	tmp = dict;
	i = 0;
	while (tmp)
	{
		box = tmp->value;
		if (x >= box->x && x <= box->x + box->width
			&& y >= box->y && y <= box->y + box->height)
		{
			if (box->mouse_press)
			{
				game->pick_obj = i;
				box->mouse_press(1, x, y, game);
			}
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	check_all_objects_release_start(t_game *game, int x, int y, t_dict *dict)
{
	t_dict			*tmp;
	t_collide_box	*box;

	tmp = dict;
	while (tmp)
	{
		box = tmp->value;
		if (x >= box->x
			&& x <= box->x + box->width
			&& y >= box->y
			&& y <= box->y + box->height)
		{
			if (box->mouse_release)
				box->mouse_release(1, x, y, game);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	startscreen_mouse_press(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->menu.error = 0;
		check_all_objects_press_start(game, x, y, game->start_menu.all_objects);
	}
	return (0);
}

int	startscreen_mouse_release(int button, int x, int y, t_game *game)
{
	if (button == 1)
		check_all_objects_release_start(game, x, y,
			game->start_menu.all_objects);
	return (0);
}

int	startscreen_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	(void)game;
	return (0);
}
