/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:42:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/28 13:20:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

#include <stdio.h>

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

int	slide(t_game *game, t_wall wall, t_coord mov)
{
	t_coord	new_mov;

	new_mov.x = 0;
	new_mov.y = 0;
	wall.dist = wall.dist * dabs(cos(get_wall_angle(wall.face) - game->player.plane.value));
	if (wall.face == 'N' || wall.face == 'S' || wall.face == 'n' || wall.face == 's')
		new_mov.x = mov.x * dabs(cos(get_wall_angle(wall.face) - game->player.plane.value));
	else
		new_mov.y = mov.y * dabs(cos(get_wall_angle(wall.face) - game->player.plane.value));
	check_collide(game, new_mov);
	return (0);
}

int	apply_collide(t_game *game, t_wall wall, t_coord mov)
{
	if (wall.dist > norm(mov.x, mov.y)
		&& wall.dist > 3 * VIEW_WIDTH / 2)
	{
		game->player.pos.x += mov.x;
		game->player.pos.y += mov.y;	
	}
	else
		slide (game, wall, mov);
	return (0);
}

int	get_new_wall(t_game *game, t_vector player, t_wall *wall, int i)
{
	wall->face = 0;
	wall->dist = 0;
	wall->dist_from_start = 0;
	intersect_wall(game, player, wall, i);
	return (0);
}

int	check_collide(t_game *game, t_coord mov)
{
	t_wall		wall;
	t_wall		wall2;
	t_vector	player;

	if (mov.x == 0 && mov.y == 0)
		return (0);
	if (mov.y > 0)
		player.angle.value = 2 * M_PI
			- acos(mov.x / norm((double)mov.x, (double)mov.y));
	else
		player.angle.value = acos(mov.x / norm((double)mov.x, (double)mov.y));
	player.angle.cos = cos(player.angle.value);
	player.angle.sin = sin(player.angle.value);
	player.angle.tan = player.angle.sin / player.angle.cos;
	player.x = game->player.pos.x + VIEW_WIDTH
		* player.angle.sin / 2;
	player.y = game->player.pos.y + VIEW_WIDTH
		* player.angle.cos / 2;
	get_new_wall(game, player, &wall, WIN_WIDTH);
	player.x = player.x - VIEW_WIDTH
		* sin(game->player.plane.value);
	player.y = player.y - VIEW_WIDTH
		* cos(game->player.plane.value);
	get_new_wall(game, player, &wall2, WIN_WIDTH);
	//printf("face: %c, face2: %c\n", wall.face, wall2.face);
	if (min(wall.dist, wall2.dist) == wall2.dist)
	{
		wall.dist = wall2.dist;
		wall.face = wall2.face;
	}
	apply_collide(game, wall, mov);
	return (0);
}
