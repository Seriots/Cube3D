/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_objects_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:43:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:45:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "ft.h"

int	move_ghost(t_game *game, t_object *obj)
{
	double	dist_x;
	double	dist_y;
	double	angle;

	dist_x = game->player.pos.x - obj->pos.x;
	dist_y = game->player.pos.y - obj->pos.y;
	angle = atan(dist_y / dist_x);
	if (dist_x < 0)
		obj->pos.x -= GHOST_SPEED * game->delay * dabs(cos(angle));
	else
		obj->pos.x += GHOST_SPEED * game->delay * dabs(cos(angle));
	if (dist_y < 0)
		obj->pos.y -= GHOST_SPEED * game->delay * dabs(sin(angle));
	else
		obj->pos.y += GHOST_SPEED * game->delay * dabs(sin(angle));
	return (0);
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
			if (dist < MIN_DIST_OBJ && (!door || dist < min_dist))
			{
				door = tmp;
				min_dist = dist;
			}
		}
		tmp = tmp->next;
	}
	return (door);
}
