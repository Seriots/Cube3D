/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_energy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 14:55:56 by lgiband          ###   ########.fr       */
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

int	energy_use(t_game *game, t_dict *dict, t_object *obj)
{
	t_object	*search;
	int			i;

	i = 0;
	while (i < game->inventory.size)
	{
		search = (t_object *)game->inventory.items[i];
		if (search && ft_strcmp(search->tag, LAMP) == 0 && search->use_count < search->use_max)
		{
			search->use_count += 30;
			if (search->use_count > search->use_max)
				search->use_count = search->use_max;
			obj->delete(game, dict, obj);
			return (0);
		}
		i++;
	}
	set_error_message(game, "No uncharged flashlight found", 2000);
	return (0);
}

int	energy_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	energy_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	energy_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	energy_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	energy_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}

int	init_energy(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, ENERGY, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.energy[GAME];
	(*obj)->menu_img = &game->all_img.energy[ICON];
	(*obj)->hand_img = &game->all_img.energy[HAND];
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame + game->delay;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = energy_interact;
	(*obj)->use = energy_use;
	(*obj)->drop = energy_drop;
	(*obj)->collide = energy_collide;
	(*obj)->update = energy_update;
	(*obj)->delete = energy_delete;
	return (0);
}
