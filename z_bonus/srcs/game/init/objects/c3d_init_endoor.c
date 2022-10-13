/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_enendoor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 11:55:48 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

#include "dict.h"

#include <stdio.h>

int	endoor_use(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	endoor_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	endoor_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	endoor_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	//printf("endoor_update, %f %f\n", obj->pos.x, obj->pos.y);
	return (0);
}

int	endoor_delete(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	endoor_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	init_endoor(t_game *game, t_object **obj)
{
	(*obj)->all_img = 0;
	(*obj)->game_img = 0;
	(*obj)->menu_img = 0;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame + game->delay;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = endoor_interact;
	(*obj)->use = endoor_use;
	(*obj)->drop = endoor_drop;
	(*obj)->collide = endoor_collide;
	(*obj)->update = endoor_update;
	(*obj)->delete = endoor_delete;
	return (0);
}
