/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startinit_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:03:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/28 11:27:38 by lgiband          ###   ########.fr       */
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
	return (0);
}
