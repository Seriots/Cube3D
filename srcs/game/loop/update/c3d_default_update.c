/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 18:56:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"

int	default_update(t_game *game)
{
	if (game->player.forward == 0)
		game->player.pos.y -= MOVE_SPEED;
	if (game->player.backward == 0)
		game->player.pos.y += MOVE_SPEED;
	if (game->player.left == 0)
		game->player.pos.x -= MOVE_SPEED;
	if (game->player.right == 0)
		game->player.pos.x += MOVE_SPEED;
	if (game->player.turn_left == 0)
	{
		game->player.rot -= TURN_SPEED;
		if (game->player.rot < 0)
			game->player.rot += 2 * M_PI;
	}
	if (game->player.turn_right == 0)
	{
		game->player.rot += TURN_SPEED;
		if (game->player.rot > 2 * M_PI)
			game->player.rot -= 2 * M_PI;
	}
	return (0);
}