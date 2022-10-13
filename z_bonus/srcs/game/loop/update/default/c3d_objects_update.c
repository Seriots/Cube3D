/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_objects_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:46:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 20:44:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

int	update_objects(t_game *game, t_dict *all_objects)
{
	t_dict		*tmp;
	t_object	*obj;

	tmp = all_objects;
	while (tmp)
	{
		obj = tmp->value;
		obj->update(game, tmp, obj);
		tmp = tmp->next;
	}
	return (0);
}
