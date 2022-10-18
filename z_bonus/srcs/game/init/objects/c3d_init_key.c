/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:43:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 15:22:56 by lgiband          ###   ########.fr       */
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

//door pos:  / casesize
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
			dist = norm(obj->pos.x - game->player.pos.x, obj->pos.y - game->player.pos.y);
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

int	key_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	key_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	key_delete(t_game *game, t_dict *dict, t_object *obj)
{
	int	i;

	i = 0;
	while (i < game->inventory.size)
	{
		if (game->inventory.items[i] == obj)
		{
			game->inventory.items[i] = NULL;
			break ;
		}
		i++;
	}
	dict_delone(&game->map.all_objects, dict, 0, free);
	return (0);
}

int	key_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}

int	init_key(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, KEY, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.key[GAME];
	(*obj)->menu_img = &game->all_img.key[ICON];
	(*obj)->hand_img = &game->all_img.key[HAND];
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = key_interact;
	(*obj)->use = key_use;
	(*obj)->drop = key_drop;
	(*obj)->collide = key_collide;
	(*obj)->update = key_update;
	(*obj)->delete = key_delete;
	return (0);
}
