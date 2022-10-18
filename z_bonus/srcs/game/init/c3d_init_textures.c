/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:59:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 19:00:47 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_init.h"
#include "mzg_incs.h"

#include "ft.h"

#include <stdio.h>

int	open_one_texture(t_game *game, t_img_data *img,
	char *path, char *default_path)
{
	int	error;

	error = init_xpm_image(game, img, path);
	if (error)
	{
		error = init_xpm_image(game, img, default_path);
		if (error)
			return (error);
	}
	return (0);
}

int	open_textures(t_game *game, t_map *map)
{
	int	error;

	game->all_img.no.img = 0;
	game->all_img.so.img = 0;
	game->all_img.ea.img = 0;
	game->all_img.we.img = 0;
	game->all_img.ce.img = 0;
	game->all_img.fl.img = 0;
	error = open_one_texture(game, &game->all_img.no,
			map->no, DEFAULT_IMAGE_PATH_NO);
	if (error)
		return (error);
	error = open_one_texture(game, &game->all_img.so,
			map->so, DEFAULT_IMAGE_PATH_SO);
	if (error)
		return (error);
	error = open_one_texture(game, &game->all_img.ea,
			map->ea, DEFAULT_IMAGE_PATH_EA);
	if (error)
		return (error);
	error = open_one_texture(game, &game->all_img.we,
			map->we, DEFAULT_IMAGE_PATH_WE);
	if (error)
		return (error);
	error = open_one_texture(game, &game->all_img.ce,
			0, DEFAULT_IMAGE_PATH_CE);
	if (error)
		return (error);
	error = open_one_texture(game, &game->all_img.fl,
			0, DEFAULT_IMAGE_PATH_FL);
	if (error)
		return (error);
	return (0);
}
