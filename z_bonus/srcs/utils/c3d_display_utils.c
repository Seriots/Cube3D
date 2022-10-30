/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:04:43 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/30 22:27:26 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include <math.h>

double	start_get_dist_obj(t_game *game, t_object *obj)
{
	double	dist;

	obj->angle = get_obj_angle(obj->pos.x - game->display.xfov,
			-obj->pos.y + game->display.yfov);
	if (check_angle(obj->angle, game->display.left_angle,
			game->display.right_angle) == 0)
		return (-1.0);
	dist = sqrt(pow(obj->pos.x - game->display.xfov, 2)
			+ pow(obj->pos.y - game->display.yfov, 2));
	if (dist <= game->settings.fov / cos(dabs(obj->angle
				- game->start_map.player.plane.value)))
		return (-1.0);
	dist -= game->settings.fov / cos(dabs(obj->angle
				- game->start_map.player.plane.value));
	return (dist);
}

int	set_screen_data(t_screen_data *pixel, double dist, int color)
{
	pixel->color = color;
	pixel->dist = dist;
	return (0);
}
