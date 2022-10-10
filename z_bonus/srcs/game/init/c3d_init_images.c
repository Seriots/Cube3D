/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 10:24:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_init.h"

int	init_images(t_game *game)
{
	int	error;

	error = init_image(game, WIN_WIDTH, WIN_HEIGHT, &game->all_img.screen_img);
	if (error)
		return (error);
	error = init_image(game, MENU_WIDTH, MENU_HEIGHT, &game->all_img.menu_img);
	if (error)
		return (error);
	error = init_image(game, MMAP_WIDTH, MMAP_HEIGHT,
			&game->all_img.minimap_img);
	if (error)
		return (error);
	error = init_images_group(game, "imgs/xpm/cursor",
			8, &game->all_img.all_cursor_img);
	if (error)
		return (error);
	return (0);
}
