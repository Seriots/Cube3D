/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_heal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:47:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 16:39:47 by lgiband          ###   ########.fr       */
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

int	heal_use(t_game *game, t_dict *dict, t_object *obj)
{
	if (game->player.life < game->player.max_life)
	{
		game->player.life ++;
		obj->delete(game, dict, obj);
	}
	else
		set_error_message(game, "You are already full life", 2000);
	return (0);
}

int	heal_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	heal_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	heal_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	heal_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	heal_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}

int	init_heal(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, HEAL, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.heal[GAME];
	(*obj)->menu_img = &game->all_img.heal[ICON];
	(*obj)->hand_img = &game->all_img.heal[HAND];
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = heal_interact;
	(*obj)->use = heal_use;
	(*obj)->drop = heal_drop;
	(*obj)->collide = heal_collide;
	(*obj)->update = heal_update;
	(*obj)->delete = heal_delete;
	return (0);
}
