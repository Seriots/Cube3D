/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:38:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 17:47:39 by lgiband          ###   ########.fr       */
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
		*mov_y -= MOVE_SPEED * sin(game->player.rot);
		*mov_x += MOVE_SPEED * cos(game->player.rot);
	}
	else if (game->player.backward == 1)
	{
		*mov_y += MOVE_SPEED * sin(game->player.rot);
		*mov_x -= MOVE_SPEED * cos(game->player.rot);
	}
	else if (game->player.left == 1)
	{
		*mov_y -= MOVE_SPEED * cos(game->player.rot);
		*mov_x -= MOVE_SPEED * sin(game->player.rot);
	}
	else if (game->player.right == 1)
	{
		*mov_y += MOVE_SPEED * cos(game->player.rot);
		*mov_x += MOVE_SPEED * sin(game->player.rot);
	}
	return (0);
}

double	get_wall_angle(char c)
{
	if (c == 'N')
		return (0);
	if (c == 'E')
		return (M_PI / 2);
	if (c == 'S')
		return (M_PI);
	if (c == 'W')
		return (3 * M_PI / 2);
	return (0);
}

int	check_collide (t_game *game, int mov_x, int mov_y)
{
	t_wall		wall;
	t_wall		wall2;
	t_vector	player;

	player.x = game->player.pos.x + VIEW_SCREEN * sin(game->player.rot) / 2;
	player.y = game->player.pos.y + VIEW_SCREEN * cos(game->player.rot) / 2;
	if (mov_y > 0)
		player.angle = 2 * M_PI - acos(mov_x / MOVE_SPEED);
	else
		player.angle = acos(mov_x / MOVE_SPEED);
	wall.face = 0;
	wall.dist = 0;
	wall.dist_from_start = 0;
	intersect_wall(game, player, &wall);
	wall.dist = wall.dist * dabs(cos(get_wall_angle(wall.face) + M_PI / 2 - player.angle));
	player.x = game->player.pos.x - VIEW_SCREEN * sin(game->player.rot) / 2;
	player.y = game->player.pos.y - VIEW_SCREEN * cos(game->player.rot) / 2;
	wall2.face = 0;
	wall2.dist = 0;
	wall2.dist_from_start = 0;
	intersect_wall(game, player, &wall2);
	wall2.dist = wall2.dist * dabs(cos(get_wall_angle(wall2.face) + M_PI / 2 - player.angle));
	if (min(wall.dist, wall2.dist) == wall2.dist)
		wall.dist = wall2.dist;
	if (wall.dist > MOVE_SPEED && wall.dist > 3 * VIEW_SCREEN / 2)
	{
		game->player.pos.x += mov_x;
		game->player.pos.y += mov_y;
	}
	return (0);
}

int	update_movement(t_game *game)
{
	float	mov_x;
	float	mov_y;

	get_movement(game, &mov_x, &mov_y);
	check_collide(game, mov_x, mov_y);
	return (0);
}

int	update_player(t_game *game)
{
	update_movement(game);
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
