/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_obj_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:45:40 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 15:08:33 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

int	init_obj(t_dict *dict, void *obj, int size)
{
	dict = malloc(sizeof(t_dict));
	if (!dict)
		return (10);
	obj = malloc(size);
	if (!obj)
		return (free(dict), 10);
	return (0);
}