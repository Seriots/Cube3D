/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_energy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/21 15:18:52 by lgiband          ###   ########.fr       */
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

int	energy_use(t_game *game, t_dict *dict, t_object *obj)
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
			search->use_count += 30;
			if (search->use_count > search->use_max)
				search->use_count = search->use_max;
			game->player.stats.use_object.value += 1;
			obj->delete(game, dict, obj);
			return (0);
		}
		i++;
	}
	set_error_message(game, "No uncharged flashlight found", 2000);
	return (0);
}

int	energy_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	energy_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
