/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_objects_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:43:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:48:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "ft.h"

int	is_player_facing(t_game *game, t_object *obj, double marge)
{
	double	angle;

	angle = get_obj_angle(obj->pos.x - game->display.xfov,
			-obj->pos.y + game->display.yfov);
	if (angle > game->player.plane.value - marge
		&& angle < game->player.plane.value + marge)
		return (1);
	if (angle > game->player.plane.value - (2 * M_PI) - marge
		&& angle < game->player.plane.value - (2 * M_PI) + marge)
		return (1);
	return (0);
}

double	get_angle_player_obj(t_game *game, t_object *obj, double marge)
{
	double	angle;

	angle = get_obj_angle(obj->pos.x - game->display.xfov,
			-obj->pos.y + game->display.yfov);
	if (angle > game->player.plane.value - marge
		&& angle < game->player.plane.value + marge)
		return (dabs(angle - game->player.plane.value));
	if (angle > game->player.plane.value - (2 * M_PI) - marge
		&& angle < game->player.plane.value - (2 * M_PI) + marge)
		return (dabs(angle - game->player.plane.value - (2 * M_PI)));
	return (0);
}

void	set_nearest(t_dict **door, t_dict **tmp, double *dist, double *min_dist)
{
	*door = *tmp;
	*min_dist = *dist;
}

t_dict	*get_nearest_door(t_game *game, t_dict **all_obj)
{
	t_dict		*tmp;
	t_dict		*door;
	double		min_dist;
	double		dist;
	t_object	*obj;

	tmp = *all_obj;
	door = 0;
	min_dist = 0;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && ft_strcmp(obj->tag, DOOR) == 0)
		{
			dist = norm(obj->pos.x - game->player.pos.x,
					obj->pos.y - game->player.pos.y);
			if (dist < MIN_DIST_OBJ
				&& (!door || dist < min_dist)
				&& is_player_facing(game, obj, 0.3))
				set_nearest(&door, &tmp, &dist, &min_dist);
		}
		tmp = tmp->next;
	}
	return (door);
}
