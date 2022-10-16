/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_lamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:44:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/16 13:50:12 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

#include "dict.h"

#include <stdio.h>

int	lamp_use(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	obj->state = !obj->state;
	return (0);
}

int	lamp_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	lamp_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	lamp_update(t_game *game, t_dict *dict, t_object *obj)
{
	t_object	*selected;

	(void)dict;
	if (game->inventory.selected < 0)
		return (0);
	selected = game->inventory.items[game->inventory.selected];
	if (obj == selected && obj->state == 1 && obj->use_count > 0)
		obj->use_count -= LAMP_DECREASE * game->delay;
	else if (obj->use_count < 100)
		obj->use_count += LAMP_INCREASE * game->delay;
		
	return (0);
}

int	lamp_delete(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	lamp_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	init_lamp(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.flashlight[0];
	(*obj)->menu_img = &game->all_img.flashlight[2];
	(*obj)->hand_img = &game->all_img.flashlight[1];
	(*obj)->state = 0;
	(*obj)->use_count = 100;
	(*obj)->use_max = 100;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame + game->delay;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = lamp_interact;
	(*obj)->use = lamp_use;
	(*obj)->drop = lamp_drop;
	(*obj)->collide = lamp_collide;
	(*obj)->update = lamp_update;
	(*obj)->delete = lamp_delete;
	return (0);
}
