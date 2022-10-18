/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generate_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:25:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 20:33:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_object.h"
#include "mzg_incs.h"

#include "ft.h"

#include <stdlib.h>

#include <stdio.h>

int	get_nb_objects(t_game *game, int width, int height)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (game->map.map[i][j] == '0')
				nb++;
			j++;
		}
		i++;
	}
	return (nb / SPAWN_OBJECTS_FACTOR);
}

int	choose_obj_map(char *obj)
{
	int	r;
	
	r = rand() % 100;
	if (r < 30)
		ft_strlcpy(obj, HEAL, 256);
	else if (r < 60)
		ft_strlcpy(obj, ENERGY, 256);
	else if (r < 80)
		ft_strlcpy(obj, BONUSHP, 256);
	else if (r < 95)
		ft_strlcpy(obj, B_ENERGY, 256);
	else if (r < 100)
		ft_strlcpy(obj, FULLHEAL, 256);
	return (0);
}

int	set_obj_map(t_game *game, char *obj, int width, int height)
{
	const char		*objs[256] = {HEAL, ENERGY, BONUSHP, B_ENERGY, FULLHEAL}; 
	unsigned long	i;
	int				x;
	int				y;

	while (1)
	{
		x = rand() % width;
		y = rand() % height;
		if (game->map.map[y][x] == '0')
			break ;
	}
	i = 0;
	while (i < sizeof(objs) / sizeof(objs[0]))
	{
		if (ft_strcmp(obj, objs[i]) == 0)
			init_obj(game, (char *)objs[i],
				x * CASE_SIZE + 8 + rand() % CASE_SIZE - 16,
				y * CASE_SIZE + 8 + rand() % CASE_SIZE - 16);
		i++;
	}
	return (0);
}

int	generate_objects(t_game *game, int width, int height)
{
	int		nb_objects;
	char	obj[256];
	int		i;

	i = 0;
	nb_objects = get_nb_objects(game, width, height);
	while (i < nb_objects)
	{
		choose_obj_map(obj);
		set_obj_map(game, obj, width, height);
		i++;
	}
	return (0);
}
