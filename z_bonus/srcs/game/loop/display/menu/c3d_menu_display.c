/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 12:15:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	display_text(t_game *game, t_dict *dict)
{
	t_dict			*tmp;

	tmp = dict;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, BUTTON) == 0)
			display_button_text(game, (t_button *)tmp->value);
		if (ft_strcmp(tmp->key, BUTTON2) == 0)
			display_button_text_start(game, (t_button *)tmp->value);
		else if (ft_strcmp(tmp->key, SLIDEBAR) == 0)
			display_slidebar_text(game, (t_slidebar *)tmp->value);
		else if (ft_strcmp(tmp->key, CHECKBOX) == 0)
			display_checkbox_text(game, (t_checkbox *)tmp->value);
		else if (ft_strcmp(tmp->key, KEYINPUT) == 0)
			display_keyinput_text(game, (t_keyinput *)tmp->value);
		else if (ft_strcmp(tmp->key, TEXTINPUT) == 0)
			display_textinput_text(game, (t_textinput *)tmp->value);
		else if (ft_strcmp(tmp->key, NUMINPUT) == 0)
			display_numinput_text(game, (t_numinput *)tmp->value);
		else if (ft_strcmp(tmp->key, MULTICHOICE) == 0)
			display_multichoice_text(game, (t_multichoice *)tmp->value);
		else if (ft_strcmp(tmp->key, SEED) == 0)
			display_seed_text(game, (t_seed *)tmp->value);
		else if (ft_strcmp(tmp->key, TEXTINPUT2) == 0)
			display_textinput_text_start(game, (t_textinput *)tmp->value);	
		tmp = tmp->next;
	}
	return (0);
}

int	menu_display(t_game *game)
{
	my_mlx_put_image_to_window(
		game, &game->all_img.menu_img,
		WIN_WIDTH / 2 - MENU_WIDTH / 2,
		WIN_HEIGHT / 2 - MENU_HEIGHT / 2);

	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	display_text(game, game->menu.all_objects);
	if (game->settings.show_fps)
		show_fps(game);
	if (game->menu.error != 0)
		display_error_on_screen(game, get_error(game->menu.error),
		MENU_ERROR_X, MENU_ERROR_Y);
	return (0);
}
