/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_inventory_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:31:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 12:41:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

int	add_items(t_inventory *inventory, t_object *object)
{
	int	i;

	i = 0;
	if (!object || !inventory)
		return (0);
	while (i < inventory->size)
	{
		if (inventory->items[i] == NULL)
		{
			inventory->items[i] = object;
			object->is_visible = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int	drop_items(t_game *game, t_inventory *inventory, t_object *object)
{
	inventory->items[inventory->selected] = NULL;
	object->is_visible = 1;
	object->pos = game->player.pos;
	return (0);
}