/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:10:37 by lgiband           #+#    #+#             */
/*   Updated: 2022/08/15 23:24:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

t_dict	*dict_new(void *key, void *value)
{
	t_dict	*new;

	if (!key)
		return (0);
	new = malloc(sizeof(t_dict));
	if (!new)
		return (0);
	new->key = key;
	new->value = value;
	new->next = 0;
	new->previous = 0;
	return (new);
}
