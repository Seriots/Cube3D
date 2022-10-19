/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_collide_player_obj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:42:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 00:16:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

int	check_collisions_objects(t_game *game, t_dict *all_objects)
{
	t_dict		*tmp;
	t_object	*obj;

	tmp = all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj->is_collide && norm(obj->pos.x - game->player.pos.x,
				obj->pos.y - game->player.pos.y) < MIN_DIST_COLLIDE)
			obj->collide(game, all_objects, obj);
		tmp = tmp->next;
	}
	return (0);
}
