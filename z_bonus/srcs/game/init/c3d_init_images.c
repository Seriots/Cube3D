/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/16 14:24:03 by lgiband          ###   ########.fr       */
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
	error = init_xpm_image(game, &game->all_img.key_icon, "imgs/xpm/object/key_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.flashlight[0], "imgs/xpm/object/black_flashlight_game.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.flashlight[1], "imgs/xpm/object/black_flashlight_hand.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.flashlight[2], "imgs/xpm/object/black_flashlight_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.hud[0], "imgs/xpm/hud/stamina_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.hud[1], "imgs/xpm/hud/heart_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.hud[2], "imgs/xpm/hud/flashlight_icon.xpm");
	if (error)
		return (error);
	error = init_images_group(game, "imgs/xpm/cursor", 8, &game->all_img.all_cursor_img);
	if (error)
		return (error);
	return (0);
}
