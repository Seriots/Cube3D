/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_omap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 21:01:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

int	omap_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	omap_update(t_game *game, t_dict *dict, t_object *obj)
{
	if (obj->use_count == 1 && obj->state != game->level)
		obj->delete(game, dict, obj);
	return (0);
}

int	omap_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	init_omap(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, MAP, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.omap[GAME];
	(*obj)->menu_img = &game->all_img.omap[ICON];
	(*obj)->hand_img = &game->all_img.omap[HAND];
	(*obj)->width = (*obj)->game_img->width * 3 / 100;
	(*obj)->height = (*obj)->game_img->height * 3 / 100;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = omap_interact;
	(*obj)->use = omap_use;
	(*obj)->drop = omap_drop;
	(*obj)->collide = omap_collide;
	(*obj)->update = omap_update;
	(*obj)->delete = omap_delete;
	return (0);
}
