/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event_mouse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 15:02:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	default_mouse_press(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	(void)button;
	//printf("Mouse pressed: %d\n", button);
	return (0);
}

int	default_mouse_release(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	(void)button;
	//printf("Mouse released: %d\n", button);
	return (0);
}

int	default_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	game->player.rot -= (((float)(x - WIN_WIDTH / 2))
			* ((SENSIBILITY + 1.0) / 5000.0));
	if (game->player.rot > 2 * M_PI)
		game->player.rot -= 2 * M_PI;
	else if (game->player.rot < 0)
		game->player.rot += 2 * M_PI;
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
