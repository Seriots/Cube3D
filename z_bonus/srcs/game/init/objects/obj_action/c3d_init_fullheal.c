/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_fullheal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:49:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:46:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

int	fullheal_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	fullheal_update(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	fullheal_delete(t_game *game, t_dict *dict, t_object *obj)
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

int	init_fullheal(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, FULLHEAL, 32);
	(*obj)->all_img = 0;
	(*obj)->game_img = &game->all_img.fullheal[GAME];
	(*obj)->menu_img = &game->all_img.fullheal[ICON];
	(*obj)->hand_img = &game->all_img.fullheal[HAND];
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
	(*obj)->interact = fullheal_interact;
	(*obj)->use = fullheal_use;
	(*obj)->drop = fullheal_drop;
	(*obj)->collide = fullheal_collide;
	(*obj)->update = fullheal_update;
	(*obj)->delete = fullheal_delete;
	return (0);
}
