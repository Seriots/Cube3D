/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 13:24:52 by lgiband          ###   ########.fr       */
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
		ft_strlcat(make_name, name, ft_strlen(name) + 9 + 1);
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

static int	init_all_objects_img(t_game *game)
{
	if (init_objects_img(game, "imgs/xpm/object/black_flashlight",
			game->all_img.flashlight)
		|| init_objects_img(game, "imgs/xpm/object/key", game->all_img.key)
		|| init_objects_img(game, "imgs/xpm/object/energy",
			game->all_img.energy)
		|| init_objects_img(game, "imgs/xpm/object/b_energy",
			game->all_img.b_energy)
		|| init_objects_img(game, "imgs/xpm/object/heal", game->all_img.heal)
		|| init_objects_img(game, "imgs/xpm/object/map", game->all_img.omap)
		|| init_objects_img(game,
			"imgs/xpm/object/syringe", game->all_img.syringe)
		|| init_objects_img(game, "imgs/xpm/object/fullheal",
			game->all_img.fullheal)
		|| init_objects_img(game, "imgs/xpm/object/bonushp",
			game->all_img.bonushp))
		return (1);
	return (0);
}

static int	init_all_xpm_img(t_game *game)
{
	if (init_xpm_image(game,
			&game->all_img.loading, "imgs/xpm/loading/loading.xpm")
		|| init_xpm_image(game,
			&game->all_img.endoor, "imgs/xpm/object/endoor_game.xpm")
		|| init_xpm_image(game, &game->all_img.score, "imgs/xpm/menu/score.xpm")
		|| init_xpm_image(game,
			&game->all_img.game_over, "imgs/xpm/menu/game_over.xpm")
		|| init_xpm_image(game,
			&game->all_img.leaderboard, "imgs/xpm/menu/leaderboard.xpm")
		|| init_xpm_image(game,
			&game->all_img.return_arrow, "imgs/xpm/menu/return.xpm")
		|| init_xpm_image(game,
			&game->all_img.logo, "imgs/xpm/menu/logo.xpm")
		|| init_images_group(game, "imgs/xpm/cursor/cursor", 8,
			&game->all_img.all_cursor_img)
		|| init_images_group(game, "imgs/xpm/ghost/ghost", 16,
			&game->all_img.all_ghost_img)
		|| init_images_group(game, "imgs/xpm/loading/frame", 15,
			&game->all_img.all_loading_img)
		|| init_images_group(game, "imgs/xpm/number/number", 10,
			&game->all_img.all_number_img)
		|| init_images_group(game, "imgs/xpm/door/door", 9,
			&game->all_img.all_door_img))
		return (1);
	return (0);
}

int	init_images(t_game *game)
{
	if (init_image(game, WIN_WIDTH, WIN_HEIGHT, &game->all_img.screen_img)
		|| init_image(game, MENU_WIDTH, MENU_HEIGHT, &game->all_img.menu_img)
		|| init_image(game, MMAP_WIDTH, MMAP_HEIGHT, &game->all_img.minimap_img)
		|| init_image(game, END_WIDTH, END_HEIGHT, &game->all_img.end_img)
		|| init_all_xpm_img(game)
		|| init_all_objects_img(game)
		|| init_hud(game))
		return (12);
	return (0);
}
