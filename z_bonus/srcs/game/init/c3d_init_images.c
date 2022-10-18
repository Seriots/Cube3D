/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 21:49:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_init.h"
#include "c3d_object.h"

#include "ft.h"

#include <stdlib.h>

int	init_objects_img(t_game *game, char *name, t_img_data dst[])
{
	const char	*tab[] = {"_game.xpm", "_hand.xpm", "_icon.xpm"};
	char		*make_name;
	int			i;
	int			error;

	make_name = ft_calloc(ft_strlen(name) + 9 + 1, sizeof(char));
	if (!make_name)
		return (10);
	i = 0;
	while (i < 3)
	{
		ft_memset(make_name, 0, ft_strlen(name) + 9 + 1);
		ft_strlcat(make_name, name, ft_strlen(name) + 1);
		ft_strlcat(make_name, tab[i], ft_strlen(name) + 9 + 1);
		error = init_xpm_image(game, &dst[i], make_name);
		if (error)
			return (free(make_name), error);
		i++;
	}
	free(make_name);
	return (0);
}

int	init_hud(t_game *game)
{
	int	error;

	error = init_xpm_image(game, &game->all_img.hud[0],
			"imgs/xpm/hud/stamina_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.hud[1],
			"imgs/xpm/hud/heart_icon.xpm");
	if (error)
		return (error);
	error = init_xpm_image(game, &game->all_img.hud[2],
			"imgs/xpm/hud/flashlight_icon.xpm");
	if (error)
		return (error);
	return (0);
}

int	init_images(t_game *game)
{
	if (init_image(game, WIN_WIDTH, WIN_HEIGHT, &game->all_img.screen_img)
		|| init_image(game, MENU_WIDTH, MENU_HEIGHT, &game->all_img.menu_img)
		|| init_image(game, MMAP_WIDTH, MMAP_HEIGHT, &game->all_img.minimap_img)
		|| init_objects_img(game, "imgs/xpm/object/black_flashlight",
			game->all_img.flashlight)
		|| init_objects_img(game, "imgs/xpm/object/key", game->all_img.key)
		|| init_objects_img(game, "imgs/xpm/object/energy",
			game->all_img.energy)
		|| init_objects_img(game, "imgs/xpm/object/b_energy",
			game->all_img.b_energy)
		|| init_objects_img(game, "imgs/xpm/object/heal", game->all_img.heal)
		|| init_objects_img(game, "imgs/xpm/object/fullheal",
			game->all_img.fullheal)
		|| init_objects_img(game, "imgs/xpm/object/bonushp",
			game->all_img.bonushp)
		|| init_images_group(game, "imgs/xpm/cursor/cursor", 8,
			&game->all_img.all_cursor_img)
		|| init_images_group(game, "imgs/xpm/ghost/ghost", 9,
			&game->all_img.all_ghost_img))
		|| init_hud(game)
		return (12);
	return (0);
}
