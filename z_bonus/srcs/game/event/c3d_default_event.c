/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:22:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 10:50:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_event.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_init.h"

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

int	move_slot(KeySym keycode, t_game *game)
{
	int	value;

	if (keycode == game->settings.slot1)
		value = 0;
	else if (keycode == game->settings.slot2)
		value = 1;
	else if (keycode == game->settings.slot3)
		value = 2;
	else if (keycode == game->settings.slot4)
		value = 3;
	else if (keycode == game->settings.slot5)
		value = 4;
	else if (keycode == game->settings.slot6)
		value = 5;
	else if (keycode == game->settings.slot7)
		value = 6;
	else if (keycode == game->settings.slot8)
		value = 7;
	else
		return (0);
	if (value > game->inventory.size - 1)
		return (0);
	else
		game->inventory.selected = value;
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
	move_slot(keycode, game);
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
	else if (keycode == XK_Escape)
		load_menu(game);
	else if (keycode == game->settings.interact)
		objects_interact(game);
	else if (keycode == game->settings.drop)
		objects_drop(game);
	return (0);
}
