/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event_mouse.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 11:38:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_settings.h"
#include "c3d_struct.h"
#include "c3d_utils.h"

#include "c3d_event.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	default_mouse_press(int button, int x, int y, t_game *game)
{
	(void)game;
	(void)x;
	(void)y;
	(void)button;
	if (button == 3)
		objects_use(game);
	return (0);
}

int	default_mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if ((button == 4 && game->settings.invert_scroll)
		|| (button == 5 && !game->settings.invert_scroll))
	{
		game->inventory.selected++;
		if (game->inventory.selected >= game->inventory.size)
			game->inventory.selected = 0;
	}
	if ((button == 5 && game->settings.invert_scroll)
		|| (button == 4 && !game->settings.invert_scroll))
	{
		game->inventory.selected--;
		if (game->inventory.selected < 0)
			game->inventory.selected = game->inventory.size - 1;
	}
	return (0);
}

int	is_invert(t_game *game)
{
	if (game->settings.invert_mouse)
		return (-1);
	return (1);
}

int	mov_hand_img(t_game *game, float mov_x, float mov_y)
{
	if (mov_x < 0)
		game->inventory.current_hand.x += (2.0);
	if (mov_x > 0)
		game->inventory.current_hand.x -= (2.0);
	if (mov_y < 0)
		game->inventory.current_hand.y += (2.0);
	if (mov_y > 0)
		game->inventory.current_hand.y -= (2.0);
	if (game->inventory.current_hand.x > HAND_MAX_X)
		game->inventory.current_hand.x = HAND_MAX_X;
	if (game->inventory.current_hand.x < -HAND_MAX_X)
		game->inventory.current_hand.x = -HAND_MAX_X;
	if (game->inventory.current_hand.y > HAND_MAX_Y)
		game->inventory.current_hand.y = HAND_MAX_Y;
	if (game->inventory.current_hand.y < -HAND_MAX_Y)
		game->inventory.current_hand.y = -HAND_MAX_Y;
	return (0);
}

int	default_mouse_move(int x, int y, t_game *game)
{
	float	mov_x;
	float	mov_y;

	mov_x = (((float)(x - WIN_WIDTH / 2)) * (game->settings.cam_sensibility_x / 70000.0)) * (is_invert(game));
	mov_y = (((float)(y - WIN_HEIGHT / 2)) * (game->settings.cam_sensibility_y / 50000.0)) * (is_invert(game));
	game->player.plane.value -= mov_x;
	game->player.angleup += mov_y;
	if (dabs(game->player.angleup) > 6)
		game->player.angleup = 6.0 * sign(game->player.angleup);
	game->player.z = -game->player.angleup + game->player.elevation;
	game->player.updown = game->player.angleup + game->player.elevation;
	if (game->player.plane.value > 2 * M_PI)
		game->player.plane.value -= 2 * M_PI;
	else if (game->player.plane.value < 0)
		game->player.plane.value += 2 * M_PI;
	game->player.plane.sin = sin(game->player.plane.value);
	game->player.plane.cos = cos(game->player.plane.value);
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mov_hand_img(game, mov_x, mov_y);
	return (0);
}
