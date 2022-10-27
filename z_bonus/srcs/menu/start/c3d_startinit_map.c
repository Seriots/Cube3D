/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startinit_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:03:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 22:04:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "mzg_incs.h"
#include "c3d_init.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"

#include "ft.h"

#include <stdlib.h>

#include <stdio.h>

int	init_map_objects(t_game *game, t_map *map)
{
	int	error;

	(void)map;
	error = init_obj(game, LAMP, 0, 0);
	if (error)
		return (error);
	return (0);
}

double	get_light_value(int i, int j)
{
	double	dist_center;

	dist_center = sqrt(pow(i - WIN_WIDTH / 2, 2) + pow(j - WIN_HEIGHT / 2, 2));
	if (dist_center > 400)
		return (0.0);
	if (dist_center < 0)
		return (1);
	return (1 - (1 - 0.0) * sqrt((dist_center - 0) / (400)));
}

int	init_light(t_display *display)
{
	int	j;
	int	i;

	j = -1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			display->light_mask[j][i] = 80000 * pow(get_light_value(i, j), 2);
	}
	return (0);
}

int	init_display(t_display *display)
{
	int	j;

	display->doors = ft_calloc(sizeof(t_door), 20);
	if (!display->doors)
		return (10);
	j = -1;
	while (++j < 20)
	{
		display->doors[j] = ft_calloc(sizeof(t_door), WIN_WIDTH + 1);
		if (!display->doors[j])
			return (10);
	}
	init_light(display);
	return (0);
}

int	init_all_map_parameters(t_game *game, int first)
{
	int	error;

	error = get_all_doors(game, &game->map);
	if (error)
		return (error);
	error = init_map_objects(game, &game->map);
	if (error)
		return (error);
	error = init_player(game, &game->map, &game->player, first);
	if (error)
		return (error);
	error = open_textures(game, &game->map);
	if (error)
		return (error);
	error = init_display(&game->display);
	if (error)
		return (error);
	return (0);
}
