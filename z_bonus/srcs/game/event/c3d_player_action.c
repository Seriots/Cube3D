/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:05:06 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 11:12:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include "dict.h"

/*check les distance a tout les objets, si dist < x alors call la fonction interact de l'obj*/
int	objects_interact(t_game *game)
{
	t_dict		*dict;
	t_object	*obj;
	double		dist;

	dict = game->map.all_objects;
	while (dict)
	{
		obj = dict->value;
		dist = dist_to_obj(game->player.pos, obj->pos);
		if (dist < MIN_DIST_OBJ)
			obj->interact(game, dict, obj);
		dict = dict->next;
	}
	return (0);
}

int	objects_drop(t_game *game)
{
	t_dict		*d_obj;
	t_object	*obj;

	obj = game->inventory.items[game->inventory.selected];
	d_obj = dict_getelem_ptr(game->map.all_objects, obj);
	obj->drop(game, d_obj, obj);
	return (0);
}

int	objects_use(t_game *game)
{
	t_dict		*d_obj;
	t_object	*obj;

	obj = game->inventory.items[game->inventory.selected];
	d_obj = dict_getelem_ptr(game->map.all_objects, obj);
	obj->use(game, d_obj, obj);
	return (0);
}
