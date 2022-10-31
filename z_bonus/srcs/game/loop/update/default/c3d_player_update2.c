/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:16:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 11:09:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdlib.h>

int	nb_touch_pressed(t_game *game)
{
	int	n;

	n = 0;
	if (game->player.left)
		n++;
	if (game->player.right)
		n++;
	if (game->player.forward)
		n++;
	if (game->player.backward)
		n++;
	if (game->player.right && game->player.left)
		n -= 1;
	if (game->player.backward && game->player.forward)
		n -= 1;
	return (n);
}

int	apply_movement(t_game *game, double *mov_x, double *mov_y)
{
	if (game->player.left >= 1)
	{
		*mov_y -= ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.cos) / 2.0) / nb_touch_pressed(game);
		*mov_x -= ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.sin) / 2.0) / nb_touch_pressed(game);
	}
	if (game->player.right >= 1)
	{
		*mov_y += ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.cos) / 2.0) / nb_touch_pressed(game);
		*mov_x += ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.sin) / 2.0) / nb_touch_pressed(game);
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
	if (game->player.forward >= 1)
	{
		*mov_y -= (min(80.0, game->player.speed * game->delay)
				* game->player.plane.sin) / nb_touch_pressed(game);
		*mov_x += (min(80.0, game->player.speed * game->delay)
				* game->player.plane.cos) / nb_touch_pressed(game);
	}
	if (game->player.backward >= 1)
	{
		*mov_y += ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.sin) / 2.0) / nb_touch_pressed(game);
		*mov_x -= ((min(80.0, game->player.speed * game->delay)
					* game->player.plane.cos) / 2.0) / nb_touch_pressed(game);
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

int	update_invicibe_frame(t_game *game)
{
	if (game->player.invincible_frames > 0)
		game->player.invincible_frames -= game->delay;
	if (game->player.invincible_frames < 0)
		game->player.invincible_frames = 0;
	return (0);
}
