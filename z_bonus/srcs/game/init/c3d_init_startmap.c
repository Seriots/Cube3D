/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_startmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:47:45 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 13:58:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_parsing.h"
#include "c3d_init.h"
#include "c3d_loop.h"

int	init_start_map(t_game *game)
{
	int	error;

	error = parsing(game, &game->start_map.map, "maps/start.cub");
	if (error)
		return (error);
	error = get_all_doors(game, &game->start_map.map);
	if (error)
		return (error);
	game->start_map.map.all_objects = game->map.all_objects;
	game->map.all_objects = 0;
	error = open_start_textures(game, &game->start_map.map);
	if (error)
		return (error);
	error = init_player(game, &game->start_map.map, &game->start_map.player, 1);
	if (error)
		return (error);
	return (0);	
}
