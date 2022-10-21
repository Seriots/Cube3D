/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:38:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/21 16:15:02 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdlib.h>

#include <stdio.h>

int	apply_movement(t_game *game, double *mov_x, double *mov_y)
{
	if (game->player.left == 1)
	{
		*mov_y -= (game->player.speed * game->delay * game->player.plane.cos)
			/ 2.0;
		*mov_x -= (game->player.speed * game->delay * game->player.plane.sin)
			/ 2.0;
	}
	else if (game->player.right == 1)
	{
		*mov_y += (game->player.speed * game->delay * game->player.plane.cos)
			/ 2.0;
		*mov_x += (game->player.speed * game->delay * game->player.plane.sin)
			/ 2.0;
	}
	return (0);
}

int	get_movement(t_game *game, double *mov_x, double *mov_y)
{
	game->player.speed = MOVE_SPEED;
	if (game->player.crouch)
		game->player.speed *= CROUCH_SPEED_FACTOR;
	if (game->player.run && game->player.stamina > 2)
		game->player.speed *= RUN_SPEED_FACTOR;
	*mov_x = 0;
	*mov_y = 0;
	if (game->player.forward == 1)
	{
		*mov_y -= (game->player.speed * game->delay * game->player.plane.sin);
		*mov_x += (game->player.speed * game->delay * game->player.plane.cos);
	}
	else if (game->player.backward == 1)
	{
		*mov_y += (game->player.speed * game->delay * game->player.plane.sin)
			/ 2.0;
		*mov_x -= (game->player.speed * game->delay * game->player.plane.cos)
			/ 2.0;
	}
	apply_movement(game, mov_x, mov_y);
	return (0);
}

int	update_movement(t_game *game)
{
	double	mov_x;
	double	mov_y;
	t_coord	mov;

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
		game->player.plane.value += TURN_SPEED;
		if (game->player.plane.value > 2 * M_PI)
			game->player.plane.value -= 2 * M_PI;
	}
	if (game->player.turn_right == 1)
	{
		game->player.plane.value -= TURN_SPEED;
		if (game->player.plane.value < 1)
			game->player.plane.value += 2 * M_PI;
	}
	game->player.plane.sin = sin(game->player.plane.value);
	game->player.plane.cos = cos(game->player.plane.value);
	if (game->player.turn_down == 1)
	{
		game->player.angleup += 0.3;
		if (game->player.angleup > 6.0)
			game->player.angleup = 6.0;
	}
	if (game->player.turn_up == 1)
	{
		game->player.angleup -= 0.3;
		if (game->player.angleup < -6.0)
			game->player.angleup = -6.0;
	}
	if (game->player.crouch)
		game->player.elevation = -CASE_SIZE / 5;
	else
		game->player.elevation = 0;
	game->player.z = -game->player.angleup + game->player.elevation;
	game->player.updown = game->player.angleup + game->player.elevation;
	return (0);
}

int	replace_hand(t_game *game)
{
	int	signe;

	if (game->inventory.current_hand.x != 0)
	{
		signe = sign(game->inventory.current_hand.x);
		game->inventory.current_hand.x
			+= (HAND_CENTER_SPEED * -signe * game->delay);
		if (signe != sign(game->inventory.current_hand.x))
			game->inventory.current_hand.x = 0;
	}
	if (game->inventory.current_hand.y != 0)
	{
		signe = sign(game->inventory.current_hand.y);
		game->inventory.current_hand.y
			+= (HAND_CENTER_SPEED * -signe * game->delay);
		if (signe != sign(game->inventory.current_hand.y))
			game->inventory.current_hand.y = 0;
	}
	return (0);
}

int	update_hand(t_game *game)
{
	if (game->player.left == 1 || game->player.turn_left == 1)
		game->inventory.current_hand.x += (HAND_MOVEMENT_SPEED * game->delay);
	if (game->player.right == 1 || game->player.turn_right == 1)
		game->inventory.current_hand.x -= (HAND_MOVEMENT_SPEED * game->delay);
	if (game->player.forward == 1 || game->player.turn_up == 1)
		game->inventory.current_hand.y += (HAND_MOVEMENT_SPEED * game->delay);
	if (game->player.backward == 1 || game->player.turn_down == 1)
		game->inventory.current_hand.y -= (HAND_MOVEMENT_SPEED * game->delay);
	if (game->inventory.current_hand.x > HAND_MAX_X)
		game->inventory.current_hand.x = HAND_MAX_X;
	if (game->inventory.current_hand.x < -HAND_MAX_X)
		game->inventory.current_hand.x = -HAND_MAX_X;
	if (game->inventory.current_hand.y > HAND_MAX_Y)
		game->inventory.current_hand.y = HAND_MAX_Y;
	if (game->inventory.current_hand.y < -HAND_MAX_Y)
		game->inventory.current_hand.y = -HAND_MAX_Y;
	replace_hand(game);
	return (0);
}

int	update_invicibe_frame(t_game *game)
{
	if (game->player.invincible_frames > 0)
		game->player.invincible_frames -= game->delay;
	if (game->player.invincible_frames < 0)
		game->player.invincible_frames = 0;
	return (0);
}

int	play_footstep(t_game *game)
{
	if (game->player.footstep_speed < 0)
	{
		if (game->player.last_footstep == 0)
			system("cvlc --play-and-exit ./test/left_foot.mp3 &");
		else
			system("cvlc --play-and-exit ./test/right_foot.mp3 &");
		game->player.last_footstep = !game->player.last_footstep;
		game->player.footstep_speed = 2000 * game->player.speed;
	}
	return (0);
}

int	update_player(t_game *game)
{
	update_movement(game);
	update_rotation(game);
	update_hand(game);
	update_invicibe_frame(game);
	if (game->player.left == 1 || game->player.right == 1
		|| game->player.forward == 1 || game->player.backward == 1)
		play_footstep(game);
	game->player.footstep_speed -= game->delay;
	return (0);
}
