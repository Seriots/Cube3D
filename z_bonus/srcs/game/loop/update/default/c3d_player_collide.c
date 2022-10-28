/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:42:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/28 06:43:25 by pierre-yves      ###   ########.fr       */
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
	if (wall.face == 'N' || wall.face == 'S')
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

int	check_angle(double angle, double playerangle)
{
	if (angle - playerangle < M_PI_2 && angle - playerangle > -M_PI_2)
		return (1);
	if (angle + 2 * M_PI - playerangle < M_PI_2 && angle + 2 * M_PI - playerangle > -M_PI_2)
		return (1);
	if (angle - 2 * M_PI- playerangle < M_PI_2 && angle - 2 * M_PI- playerangle > -M_PI_2)
		return (1);
	return (0);
}

int	get_corner_dist(t_game *game, double dist)
{
	int	i;
	int	j;
	double	angle1;
	double	angle2;
	double	angle3;
	double	angle4;

	i = game->player.pos.x / CASE_SIZE;
	j = game->player.pos.y / CASE_SIZE;
	angle1 = atan(((j + 1) * CASE_SIZE - game->player.pos.y) / (i * CASE_SIZE - game->player.pos.x)) + M_PI;
	angle2 = atan(((j) * CASE_SIZE - game->player.pos.y) / (i * CASE_SIZE - game->player.pos.x)) + M_PI;
	angle3 = atan(((j + 1) * CASE_SIZE - game->player.pos.y) / ((i + 1) * CASE_SIZE - game->player.pos.x));
	angle4 = atan(((j) * CASE_SIZE - game->player.pos.y) / ((i + 1) * CASE_SIZE - game->player.pos.x));
	if (check_angle(angle1, game->player.plane.value) && dist >)
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
	player.angle.cos = sign(mov.x);
	player.angle.sin = 0;
	player.angle.tan = 0;
	get_new_wall(game, player, &wallh, WIN_WIDTH);
	player.angle.value = M_PI + sign(mov.y) * M_PI_2;
	player.angle.cos = 0;
	player.angle.sin = -sign(mov.y);
	player.angle.tan = player.angle.sin / player.angle.cos;
	get_new_wall(game, player, &wallv, WIN_WIDTH);
	if (wallh.dist - CASE_SIZE / 4 < dabs(mov.x))
		mov.x = pure_sign(mov.x) * (wallh.dist - CASE_SIZE / 4);
	if (wallv.dist - CASE_SIZE / 4 < dabs(mov.y))
		mov.y = pure_sign(mov.y) * (wallv.dist - CASE_SIZE / 4);
	game->player.pos.x += mov.x;
	game->player.pos.y += mov.y;
	return (0);
}