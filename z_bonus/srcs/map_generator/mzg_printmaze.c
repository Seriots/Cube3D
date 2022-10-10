/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_printmaze.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:27:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 15:32:11 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"

#include "c3d_struct.h"
#include "mzg_incs.h"

#include "ft.h"

#include <stdio.h>

int	print_objects(t_dict *all_objects)
{
	t_dict	*tmp;

	tmp = all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "KEY") == 0)
			printf("%s: %d %d\n", (char *)tmp->key,
				((t_key *)tmp->value)->x, ((t_key *)tmp->value)->y);
		tmp = tmp->next;
	}
	return (0);
}

int	print_settings(void)
{
	printf("NO %s\n", DEFAULT_IMAGE_PATH_NO);
	printf("SO %s\n", DEFAULT_IMAGE_PATH_SO);
	printf("WE %s\n", DEFAULT_IMAGE_PATH_WE);
	printf("EA %s\n", DEFAULT_IMAGE_PATH_EA);
	printf("C %s\n", DEFAULT_CEIL);
	printf("F %s\n", DEFAULT_FLOOR);
	return (0);
}

int	printmaze(t_map *map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	print_settings();
	print_objects(map->all_objects);
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			printf("%c", map->map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
	return (0);
}
