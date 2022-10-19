/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:43:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:54:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include <stdio.h>

int	key_use(t_game *game, t_dict *dict, t_object *obj)
{
	t_dict		*d_search;
	t_object	*search;		

	d_search = get_nearest_door(game, &game->map.all_objects);
	if (d_search)
	{
		search = d_search->value;
		if (search->state == 0)
		{
			search->interact(game, dict, search);
			obj->delete(game, dict, obj);
		}
		else
			set_error_message(game, "Door is already open", 2000);
	}
	else
		set_error_message(game, "Too Far from door", 2000);
	return (0);
}

int	key_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	key_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
