/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_bonushp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:51:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 18:41:24 by ppajot           ###   ########.fr       */
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

int	bonushp_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	bonushp_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	bonushp_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	init_bonushp(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, BONUSHP, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.bonushp[GAME];
	(*obj)->menu_img = &game->all_img.bonushp[ICON];
	(*obj)->hand_img = &game->all_img.bonushp[HAND];
	(*obj)->width = (*obj)->game_img->width / 100 * 20;
	(*obj)->height = (*obj)->game_img->height / 100 * 20;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = 1;
	(*obj)->animation_duration = 0;
	(*obj)->interact = bonushp_interact;
	(*obj)->use = bonushp_use;
	(*obj)->drop = bonushp_drop;
	(*obj)->collide = bonushp_collide;
	(*obj)->update = bonushp_update;
	(*obj)->delete = bonushp_delete;
	return (0);
}
