/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_getelem_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:59:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 10:59:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "ft.h"

t_dict	*dict_getelem_ptr(t_dict *dict, void *ptr)
{
	if (!dict || !ptr)
		return (0);
	dict = dict_get_first(dict);
	while (dict && dict->value != ptr)
		dict = dict->next;
	return (dict);
}
