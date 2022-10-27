/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:52:07 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 21:54:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"

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
