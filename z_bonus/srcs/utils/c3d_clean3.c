/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:52:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/30 21:39:46 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"

#include <stdlib.h>

void	free_images3(t_game *game)
{
	if (game->all_img.all_cursor_img)
		free_img_array(game, &game->all_img.all_cursor_img, 8);
	if (game->all_img.all_number_img)
		free_img_array(game, &game->all_img.all_number_img, 10);
	if (game->all_img.all_ghost_img)
		free_img_array(game, &game->all_img.all_ghost_img, 16);
	if (game->all_img.all_loading_img)
		free_img_array(game, &game->all_img.all_loading_img, 15);
	if (game->all_img.all_door_img)
		free_img_array(game, &game->all_img.all_door_img, 10);
}

int	free_doors(t_game *game)
{
	int	i;

	i = 0;
	while (i < WIN_WIDTH && game->display.doors[i].door_tab)
	{
		free(game->display.doors[i].door_tab);
		i++;
	}
	free(game->display.doors);
	game->display.doors = 0;
	return (0);
}

void	free_lightmask(double **array)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = 0;
}
