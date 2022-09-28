/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:22:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 19:04:56 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_event.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <stdio.h>

int	default_key_press(int keycode, t_game *game)
{
	(void)game;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	default_key_release(int keycode, t_game *game)
{
	(void)game;
	printf("Key released: %d\n", keycode);
	if (keycode == XK_Escape)
		close_window(game);
	return (0);
}

int	default_mouse_press(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	printf("Mouse pressed: %d\n", button);
	return (0);
}

int	default_mouse_release(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	printf("Mouse released: %d\n", button);
	return (0);
}


int	default_mouse_move(int x, int y, t_game *game)
{
	game->player.pos.x += (float)(x - WIN_WIDTH / 2) * ((SENSIBILITY + 1.0) / 100.0);
	game->player.pos.y += (float)(y - WIN_HEIGHT / 2) * ((SENSIBILITY + 1.0) / 100.0);
	mlx_mouse_move(game->mlx.display, game->mlx.window, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
