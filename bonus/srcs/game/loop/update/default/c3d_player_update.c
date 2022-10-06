/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:38:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"
#include "c3d_utils_bonus.h"
#include "c3d_loop_bonus.h"

#include <math.h>

#include <stdio.h>

int	get_movement(t_game *game, float *mov_x, float *mov_y)
{
	*mov_x = 0;
	*mov_y = 0;
	if (game->player.forward == 1)
	{
		*mov_y -= MOVE_SPEED * sin(game->player.rot);
		*mov_x += MOVE_SPEED * cos(game->player.rot);
	}
	else if (game->player.backward == 1)
	{
		*mov_y += (MOVE_SPEED * sin(game->player.rot)) / 2.0;
		*mov_x -= (MOVE_SPEED * cos(game->player.rot)) / 2.0;
	}
	else if (game->player.left == 1)
	{
		*mov_y -= (MOVE_SPEED * cos(game->player.rot)) / 2.0;
		*mov_x -= (MOVE_SPEED * sin(game->player.rot)) / 2.0;
	}
	else if (game->player.right == 1)
	{
		*mov_y += (MOVE_SPEED * cos(game->player.rot)) / 2.0;
		*mov_x += (MOVE_SPEED * sin(game->player.rot)) / 2.0;
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
		game->player.rot += TURN_SPEED;
		if (game->player.rot > 2 * M_PI)
			game->player.rot -= 2 * M_PI;
	}
	if (game->player.turn_right == 1)
	{
		game->player.rot -= TURN_SPEED;
		if (game->player.rot < 1)
			game->player.rot += 2 * M_PI;
	}
	return (0);
}

int	update_player(t_game *game)
{
	update_movement(game);
	update_rotation(game);
	return (0);
}
