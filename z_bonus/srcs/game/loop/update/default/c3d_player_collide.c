/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:42:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 19:06:10 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

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

int	slide(t_game *game, t_wall wall, double limit, t_point mov)
{
	t_point	new_mov;

	new_mov.x = 0;
	new_mov.y = 0;
	if (wall.face == 'N' || wall.face == 'S')
		new_mov.x = mov.x * limit / MOVE_SPEED;
	else
		new_mov.y = mov.y * limit / MOVE_SPEED;
	check_collide(game, new_mov);
	return (0);
}

int	apply_collide(t_game *game, t_wall wall, t_point mov)
{
	if (wall.dist > norm((double)mov.x, (double)mov.y)
		&& wall.dist > 3 * VIEW_SCREEN / 2)
	{
		game->player.pos.x += mov.x;
		game->player.pos.y += mov.y;
	}
	else
		slide (game, wall, wall.dist, mov);
	return (0);
}

int	get_new_wall(t_game *game, t_vector player, t_wall *wall)
{
	wall->face = 0;
	wall->dist = 0;
	wall->dist_from_start = 0;
	intersect_wall(game, player, wall);
	wall->dist = wall->dist * dabs(cos(get_wall_angle(wall->face)
				+ M_PI / 2 - player.angle));
	return (0);
}

int	check_collide(t_game *game, t_point mov)
{
	t_wall		wall;
	t_wall		wall2;
	t_vector	player;

	if (mov.x == 0 && mov.y == 0)
		return (0);
	player.x = game->player.pos.x + VIEW_SCREEN * sin(game->player.angle_plane) / 2;
	player.y = game->player.pos.y + VIEW_SCREEN * cos(game->player.angle_plane) / 2;
	if (mov.y > 0)
		player.angle = 2 * M_PI
			- acos(mov.x / norm((double)mov.x, (double)mov.y));
	else
		player.angle = acos(mov.x / norm((double)mov.x, (double)mov.y));
	get_new_wall(game, player, &wall);
	player.x = game->player.pos.x - VIEW_SCREEN * sin(game->player.angle_plane) / 2;
	player.y = game->player.pos.y - VIEW_SCREEN * cos(game->player.angle_plane) / 2;
	get_new_wall(game, player, &wall2);
	if (min(wall.dist, wall2.dist) == wall2.dist)
	{
		wall.dist = wall2.dist;
		wall.face = wall2.face;
	}
	apply_collide(game, wall, mov);
	return (0);
}
