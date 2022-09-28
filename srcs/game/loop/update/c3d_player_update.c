/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:38:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 13:34:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

int	update_movement(t_game *game)
{
	int	mov_x;
	int	mov_y;

	mov_x = 0;
	mov_y = 0;
	if (game->player.forward == 1)
		mov_y += MOVE_SPEED;
	if (game->player.backward == 1)
		mov_y -= MOVE_SPEED;
	if (game->player.left == 1)
		mov_x += MOVE_SPEED;
	if (game->player.right == 1)
		mov_x -= MOVE_SPEED;
	if (game->map.map[(int)game->player.pos.y / CASE_SIZE][((int)game->player.pos.x + mov_x) / CASE_SIZE] != '1')
		game->player.pos.x += mov_x;
	if (game->map.map[((int)game->player.pos.y + mov_y) / CASE_SIZE][(int)game->player.pos.x  / CASE_SIZE] != '1')
		game->player.pos.y += mov_y;
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
