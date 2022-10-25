/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/25 13:11:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "mlx.h"

#include <stdio.h>

static int	init_hooks(t_game *game)
{
	mlx_do_key_autorepeatoff(game->mlx.display);
	if (HIDE == 1)
		mlx_mouse_hide(game->mlx.display, game->mlx.window);
	mlx_hook(game->mlx.window, 2, 1L << 0, &event_key_press, game);
	mlx_hook(game->mlx.window, 3, 1L << 1, &event_key_release, game);
	mlx_hook(game->mlx.window, 4, 1L << 2, &event_mouse_press, game);
	mlx_hook(game->mlx.window, 5, 1L << 3, &event_mouse_release, game);
	mlx_hook(game->mlx.window, 6, 1L << 6, &event_mouse_move, game);
	mlx_hook(game->mlx.window, 17, 1L << 17, &close_window, game);
	mlx_loop_hook(game->mlx.display, game_loop, game);
	return (0);
}

int	init_mlx(t_game *game)
{
	game->mlx.display = mlx_init();
	if (!game->mlx.display)
		return (13);
	game->mlx.window = mlx_new_window(game->mlx.display,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->mlx.window)
		return (14);
	init_hooks(game);
	return (0);
}
