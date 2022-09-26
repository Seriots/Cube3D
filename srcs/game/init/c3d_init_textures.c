/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:59:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 13:01:52 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_init.h"

#include <stdio.h>

int	open_textures(t_game *game, t_map *map)
{
	int	error;

	game->all_img.no.img = 0;
	game->all_img.so.img = 0;
	game->all_img.ea.img = 0;
	game->all_img.we.img = 0;
	error = init_xpm_image(game, &game->all_img.no, map->no);
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.so, map->so);
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.we, map->we);
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.ea, map->ea);
	if (error)
		return (error);
	return (0);
}
