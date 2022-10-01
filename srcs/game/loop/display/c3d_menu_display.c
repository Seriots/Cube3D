/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 17:26:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	display_text(t_game *game)
{
	t_dict			*tmp;
	t_collide_box	box;
	
	tmp = game->menu.all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "BUTTON") == 0)
			box = ((t_button *)tmp->value)->box;
		else if (ft_strcmp(tmp->key, "SLIDEBAR") == 0)
			box = ((t_slidebar *)tmp->value)->box;
		else
		{
			tmp = tmp->next;
			continue;
		}
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + box.x_text,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + box.y_text, 0xAAAAAA,
			box.description);
		tmp = tmp->next;
	}
	return (0);
}

int	menu_display(t_game *game)
{
	my_mlx_put_image_to_window(
		game,
		&game->all_img.menu_img,
		WIN_WIDTH / 2 - MENU_WIDTH / 2,
		WIN_HEIGHT / 2 - MENU_HEIGHT / 2
	);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window, game->all_img.screen_img.img, 0, 0);
	display_text(game);
	return (0);
}