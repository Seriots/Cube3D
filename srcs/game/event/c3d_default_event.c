/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:22:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 10:51:25 by lgiband          ###   ########.fr       */
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

int	up_already_pressed(t_game *game)
{
	if (game->player.backward != 0)
		game->player.backward += 1;
	if (game->player.forward != 0)
		game->player.forward += 1;
	if (game->player.left != 0)
		game->player.left += 1;
	if (game->player.right != 0)
		game->player.right += 1;
	return (0);
}

int	down_everyone(t_game *game, int *value)
{
	if (game->player.backward > *value)
		game->player.backward -= 1;
	if (game->player.forward > *value)
		game->player.forward -= 1;
	if (game->player.left > *value)
		game->player.left -= 1;
	if (game->player.right > *value)
		game->player.right -= 1;
	*value = 0;
	return (0);
}

int	default_key_press(KeySym keycode, t_game *game)
{
	if (keycode == game->settings.left
		|| keycode == game->settings.right
		|| keycode == game->settings.forward
		|| keycode == game->settings.backward)
		up_already_pressed(game);
	if (keycode == game->settings.left)
		game->player.left = 1;
	else if (keycode == game->settings.right)
		game->player.right = 1;
	else if (keycode == game->settings.forward)
		game->player.forward = 1;
	else if (keycode == game->settings.backward)
		game->player.backward = 1;
	else if (keycode == game->settings.turn_left)
		game->player.turn_left = 1;
	else if (keycode == game->settings.turn_right)
		game->player.turn_right = 1;
	return (0);
}

int	default_key_release(KeySym keycode, t_game *game)
{
	if (keycode == game->settings.left)
		down_everyone(game, &game->player.left);
	else if (keycode == game->settings.right)
		down_everyone(game, &game->player.right);
	else if (keycode == game->settings.forward)
		down_everyone(game, &game->player.forward);
	else if (keycode == game->settings.backward)
		down_everyone(game, &game->player.backward);
	else if (keycode == game->settings.turn_left)
		game->player.turn_left = 0;
	else if (keycode == game->settings.turn_right)
		game->player.turn_right = 0;
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
