/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 16:04:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	default_update(t_game *game)
{
	update_player(game);
	update_minimap(game);
	//printf("player_x: %f, player_y: %f, player.rot: %f\n", game->player.pos.x, game->player.pos.y, game->player.rot);
	return (0);
}
