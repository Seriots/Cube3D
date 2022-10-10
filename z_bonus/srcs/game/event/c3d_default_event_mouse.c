/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event_mouse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 21:31:36 by ppajot           ###   ########.fr       */
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
	return (0);
}

int	default_mouse_release(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	(void)button;
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
	game->player.angle_plane -= (((float)(x - WIN_WIDTH / 2))
			* (game->settings.cam_sensibility_x / 70000.0)) * (is_invert(game));
	if (game->player.angle_plane > 2 * M_PI)
		game->player.angle_plane -= 2 * M_PI;
	else if (game->player.angle_plane < 0)
		game->player.angle_plane += 2 * M_PI;
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
