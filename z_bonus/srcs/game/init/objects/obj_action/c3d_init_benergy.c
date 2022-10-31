/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_benergy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:45:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

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

int	init_benergy(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, B_ENERGY, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.b_energy[GAME];
	(*obj)->menu_img = &game->all_img.b_energy[ICON];
	(*obj)->hand_img = &game->all_img.b_energy[HAND];
	(*obj)->width = (*obj)->game_img->width * 10 / 100;
	(*obj)->height = (*obj)->game_img->height * 10 / 100;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 1;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 0;
	(*obj)->start_frame = game->last_frame;
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
