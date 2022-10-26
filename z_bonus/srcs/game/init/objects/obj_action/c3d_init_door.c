/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 16:38:41 by lgiband          ###   ########.fr       */
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

int	door_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	door_update(t_game *game, t_dict *dict, t_object *obj)
{
	int	image_value;

	(void)game;
	(void)dict;
	if (obj->state == 0)
		obj->game_img = &obj->all_img[0];
	else
	{
		if (game->last_frame - obj->start_frame > obj->animation_duration)
			obj->game_img = &obj->all_img[obj->nb_image - 1];
		else
		{
			image_value = (game->last_frame - obj->start_frame)
				/ (obj->animation_duration / obj->nb_image);
			if (image_value > obj->nb_image - 1)
				image_value = obj->nb_image - 1;
			obj->game_img = &obj->all_img[image_value];
		}
	}
	return (0);
}

int	door_delete(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	init_door(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, DOOR, 32);
	(*obj)->all_img = game->all_img.all_door_img;
	(*obj)->collide = door_collide;
	(*obj)->update = door_update;
	(*obj)->delete = door_delete;
	(*obj)->game_img = &game->all_img.all_door_img[0];
	(*obj)->menu_img = 0;
	(*obj)->hand_img = 0;
	(*obj)->width = CASE_SIZE;
	(*obj)->height = CASE_SIZE;
	(*obj)->state = 0;
	(*obj)->face = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 0;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = DOOR_NB_IMAGE;
	(*obj)->animation_duration = DOOR_DURATION;
	(*obj)->interact = door_interact;
	(*obj)->use = door_use;
	(*obj)->drop = door_drop;
	(*obj)->collide = door_collide;
	(*obj)->update = door_update;
	(*obj)->delete = door_delete;
	return (0);
}
