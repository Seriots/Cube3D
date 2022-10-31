/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_endoor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:53:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:46:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"
#include "c3d_loop.h"

#include "dict.h"
#include "ft.h"

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
	return (0);
}

int	endoor_delete(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	init_endoor(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, ENDOOR, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.endoor;
	(*obj)->menu_img = 0;
	(*obj)->hand_img = 0;
	(*obj)->width = (*obj)->game_img->width * 20 / 100;
	(*obj)->height = (*obj)->game_img->height * 20 / 100;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 1;
	(*obj)->start_frame = game->last_frame;
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
