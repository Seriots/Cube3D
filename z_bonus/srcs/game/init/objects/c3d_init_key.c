/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:43:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:27:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

#include "dict.h"

int	init_key(t_dict **all_objects, int x, int y)
{
	t_dict	*new;
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (10);
	key->x = x;
	key->y = y;
	key->state = 0;
	new = dict_new("KEY", key);
	if (!new)
		return (free(key), 10);
	dict_add_back(all_objects, new);
	return (0);
}
