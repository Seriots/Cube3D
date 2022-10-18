/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_obj_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 17:35:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_object.h"

#include "ft.h"
#include "dict.h"

int	set_obj(t_game *game, t_object **object, char *key)
{
	const t_init	all_tag[] = {{GHOST, init_ghost}, {KEY, init_key},
		{DOOR, init_door}, {ENDOOR, init_endoor}, {LAMP, init_lamp},
		{HEAL, init_heal}, {FULLHEAL, init_fullheal}, {ENERGY, init_energy},
		{B_ENERGY, init_benergy}, {BONUSHP, init_bonushp}};
	unsigned int	i;

	i = 0;
	while (i < sizeof(all_tag) / sizeof(all_tag[0]))
	{
		if (!ft_strcmp(key, all_tag[i].tag))
			return (all_tag[i].fct(game, object));
		i++;
	}
	return (0);
}

int	init_obj(t_game *game, char *tag, int x, int y)
{
	t_dict		*new;
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (10);
	*obj = (t_object){.pos.x = x, .pos.y = y};
	set_obj(game, &obj, tag);
	new = dict_new(tag, obj);
	if (!new)
		return (free(obj), 10);
	dict_add_back(&game->map.all_objects, new);
	return (0);
}
