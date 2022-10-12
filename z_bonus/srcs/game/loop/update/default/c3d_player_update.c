/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:38:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 20:57:23 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdio.h>

int	get_movement(t_game *game, float *mov_x, float *mov_y)
{
	*mov_x = 0;
	*mov_y = 0;
	if (game->player.forward == 1)
	{
		*mov_y -= MOVE_SPEED * sin(game->player.angle_plane);
		*mov_x += MOVE_SPEED * cos(game->player.angle_plane);
	}
	else if (game->player.backward == 1)
	{
		*mov_y += (MOVE_SPEED * sin(game->player.angle_plane)) / 2.0;
		*mov_x -= (MOVE_SPEED * cos(game->player.angle_plane)) / 2.0;
	}
	else if (game->player.left == 1)
	{
		*mov_y -= (MOVE_SPEED * cos(game->player.angle_plane)) / 2.0;
		*mov_x -= (MOVE_SPEED * sin(game->player.angle_plane)) / 2.0;
	}
	else if (game->player.right == 1)
	{
		*mov_y += (MOVE_SPEED * cos(game->player.angle_plane)) / 2.0;
		*mov_x += (MOVE_SPEED * sin(game->player.angle_plane)) / 2.0;
	}
	return (0);
}

int	update_movement(t_game *game)
{
	float	mov_x;
	float	mov_y;
	t_point	mov;

	get_movement(game, &mov_x, &mov_y);
	mov.x = mov_x;
	mov.y = mov_y;
	check_collide(game, mov);
	return (0);
}

int	update_rotation(t_game *game)
{
	if (game->player.turn_left == 1)
	{
		game->player.angle_plane += TURN_SPEED;
		if (game->player.angle_plane > 2 * M_PI)
			game->player.angle_plane -= 2 * M_PI;
	}
	if (game->player.turn_right == 1)
	{
		game->player.angle_plane -= TURN_SPEED;
		if (game->player.angle_plane < 1)
			game->player.angle_plane += 2 * M_PI;
	}
	if (game->player.turn_up == 1)
	{
		game->player.updown -= 0.3;
		if (game->player.updown < -9.0)
			game->player.updown = -9.0;
		game->player.z = -game->player.updown;
	}
	if (game->player.turn_down == 1)
	{
		game->player.updown += 0.3;
		if (game->player.updown > 9.0)
			game->player.updown = 9.0;
		game->player.z = -game->player.updown;
	}
	return (0);
}

int	update_player(t_game *game)
{
	update_movement(game);
	update_rotation(game);
	return (0);
}
