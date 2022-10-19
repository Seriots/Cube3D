/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_benergy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:52:10 by lgiband          ###   ########.fr       */
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
		if (search && ft_strcmp(search->tag, LAMP) == 0
			&& search->use_count < search->use_max)
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

int	benergy_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
