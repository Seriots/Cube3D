/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:42:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:58:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

int	get_new_wall(t_game *game, t_vector player, t_wall *wall, int i)
{
	wall->face = 0;
	wall->dist = 0;
	wall->dist_from_start = 0;
	intersect_wall(game, player, wall, i);
	return (0);
}

int	set_player_angle(t_vector *player, double cos, double sin)
{
	player->angle.cos = cos;
	player->angle.sin = sin;
	player->angle.tan = sin / cos;
	return (0);
}

int	check_collide(t_game *game, t_coord mov)
{
	t_wall		wallh;
	t_wall		wallv;
	t_vector	player;

	if (mov.x == 0 && mov.y == 0)
		return (0);
	player.x = game->player.pos.x;
	player.y = game->player.pos.y;
	player.angle.value = M_PI_2 - sign(mov.x) * M_PI_2;
	set_player_angle(&player, sign(mov.x), 0);
	get_new_wall(game, player, &wallh, WIN_WIDTH);
	player.angle.value = M_PI + sign(mov.y) * M_PI_2;
	set_player_angle(&player, 0, -sign(mov.y));
	get_new_wall(game, player, &wallv, WIN_WIDTH);
	while (corner_coll(game, &mov))
		;
	if (wallh.dist - CASE_SIZE / 4 < dabs(mov.x))
		mov.x = pure_sign(mov.x) * (wallh.dist - CASE_SIZE / 4);
	if (wallv.dist - CASE_SIZE / 4 < dabs(mov.y))
		mov.y = pure_sign(mov.y) * (wallv.dist - CASE_SIZE / 4);
	game->player.pos.x += mov.x;
	game->player.pos.y += mov.y;
	return (0);
}
