/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_score_event_mouse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:42:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:46:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "ft.h"
#include "mlx.h"

int	scorescreen_mouse_press(int button, int x, int y, t_game *game)
{
	if (button == 1)
	{
		game->start_menu.error = 0;
		check_all_objects_press_start(game, x, y, game->score_menu.all_objects);
	}
	return (0);
}

int	scorescreen_mouse_release(int button, int x, int y, t_game *game)
{
	if (button == 1)
		check_all_objects_release_start(game, x, y,
			game->score_menu.all_objects);
	else if ((button == 4 && !game->settings.invert_scroll)
		|| (button == 5 && game->settings.invert_scroll))
		scroll_up(game, &game->score_menu, SCROLLBAR3);
	else if ((button == 4 && game->settings.invert_scroll)
		|| (button == 5 && !game->settings.invert_scroll))
		scroll_down(game, &game->score_menu, SCROLLBAR3);
	return (0);
}

int	scorescreen_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	(void)game;
	return (0);
}
