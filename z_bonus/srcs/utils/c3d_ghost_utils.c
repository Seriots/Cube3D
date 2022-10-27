/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_ghost_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:49:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 21:50:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "ft.h"

#include <math.h>

int	ghost_touch_player(t_game *game, t_object *obj,
	double dist_x, double dist_y)
{
	double	angle;

	angle = atan(dist_y / dist_x);
	if (sign(dist_x) != sign(game->player.pos.x - obj->pos.x) || sign(dist_y)
		!= sign(game->player.pos.y - obj->pos.y))
	{
		if (dist_x < 0)
			obj->pos.x = game->player.pos.x - 5 * cos(angle);
		else
			obj->pos.x = game->player.pos.x + 5 * cos(angle);
		if (dist_y < 0)
			obj->pos.y = game->player.pos.y - 5 * sin(angle);
		else
			obj->pos.y = game->player.pos.y + 5 * sin(angle);
	}
	return (0);
}

int	move_ghost(t_game *game, t_object *obj)
{
	double	dist_x;
	double	dist_y;
	double	angle;

	dist_x = game->player.pos.x - obj->pos.x;
	dist_y = game->player.pos.y - obj->pos.y;
	angle = atan(dist_y / dist_x);
	if (dist_x < 0)
		obj->pos.x -= (GHOST_SPEED + 0.015 * game->settings.difficulty
				+ 0.005 * game->level) * game->delay * dabs(cos(angle));
	else
		obj->pos.x += (GHOST_SPEED + 0.015 * game->settings.difficulty
				+ 0.005 * game->level) * game->delay * dabs(cos(angle));
	if (dist_y < 0)
		obj->pos.y -= (GHOST_SPEED + 0.015 * game->settings.difficulty
				+ 0.005 * game->level) * game->delay * dabs(sin(angle));
	else
		obj->pos.y += (GHOST_SPEED + 0.015 * game->settings.difficulty
				+ 0.005 * game->level) * game->delay * dabs(sin(angle));
	ghost_touch_player(game, obj, dist_x, dist_y);
	return (0);
}
