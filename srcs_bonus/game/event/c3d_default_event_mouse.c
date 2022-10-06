/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event_mouse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:15:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings_bonus.h"
#include "c3d_struct_bonus.h"

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

int	is_invert(t_game *game)
{
	if (game->settings.invert_mouse)
		return (-1);
	return (1);
}

int	default_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	game->player.rot -= (((float)(x - WIN_WIDTH / 2))
		* (game->settings.cam_sensibility_x / 70000.0)) * (is_invert(game));
	if (game->player.rot > 2 * M_PI)
		game->player.rot -= 2 * M_PI;
	else if (game->player.rot < 0)
		game->player.rot += 2 * M_PI;
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
