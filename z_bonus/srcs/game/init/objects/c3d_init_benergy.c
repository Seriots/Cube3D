/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_bbenergy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 13:50:57 by lgiband          ###   ########.fr       */
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

int	benergy_use(t_game *game, t_dict *dict, t_object *obj)
{
	t_object	*search;
	int			i;

	i = 0;
	while (i < game->inventory.size)
	{
		search = (t_object *)game->inventory.items[i];
		if (search && ft_strcmp(search->tag, LAMP) == 0 && search->use_count < search->use_max)
		{
			search->use_count += 80;
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

int	benergy_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	benergy_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	benergy_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	benergy_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	benergy_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}

int	init_benergy(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, B_ENERGY, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.b_energy[GAME];
	(*obj)->menu_img = &game->all_img.b_energy[ICON];
	(*obj)->hand_img = &game->all_img.b_energy[HAND];
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame + game->delay;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = benergy_interact;
	(*obj)->use = benergy_use;
	(*obj)->drop = benergy_drop;
	(*obj)->collide = benergy_collide;
	(*obj)->update = benergy_update;
	(*obj)->delete = benergy_delete;
	return (0);
}
