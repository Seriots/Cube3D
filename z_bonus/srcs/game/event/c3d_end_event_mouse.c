/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_end_event_mouse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:47:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 21:36:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

int	check_all_objects_press_end(t_game *game, int x, int y, t_dict *dict)
{
	t_dict			*tmp;
	t_collide_box	*box;
	int				i;

	tmp = dict;
	i = 0;
	while (tmp)
	{
		box = tmp->value;
		if (check_one_obj_press_end(game, x, y, tmp))
		{
			game->pick_obj = i;
			box->mouse_press(1, x, y, game);
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	check_all_objects_release_end(t_game *game, int x, int y, t_dict *dict)
{
	t_dict			*tmp;
	t_collide_box	*box;
	int				i;

	tmp = dict;
	i = 0;
	while (tmp)
	{
		box = tmp->value;
		if (x - (WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) >= box->x
			&& x - (WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) <= box->x + box->width
			&& y - (WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) >= box->y
			&& y - (WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) <= box->y + box->height)
		{
			if (box->mouse_release)
			{
				game->pick_obj = i;
				box->mouse_release(1, x, y, game);
			}
			break ;
		}
		i++;
		tmp = tmp->next;
	}
	return (0);
}

int	end_mouse_press(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->end_menu.error = 0;
		check_all_objects_press_end(game, x, y, game->end_menu.all_objects);
	}
	return (0);
}

int	end_mouse_release(int button, int x, int y, t_game *game)
{
	if (button == 1)
		check_all_objects_release_end(game, x, y, game->end_menu.all_objects);
	else if ((button == 4 && !game->settings.invert_scroll)
		|| (button == 5 && game->settings.invert_scroll))
		scroll_up(game, &game->end_menu);
	else if ((button == 4 && game->settings.invert_scroll)
		|| (button == 5 && !game->settings.invert_scroll))
		scroll_down(game, &game->end_menu);
	return (0);
}

int	end_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	(void)game;
	return (0);
}
