/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:58:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 11:03:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_init.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

void	init_textinput(t_textinput *textinput)
{
	textinput->is_selected = 0;
	textinput->shift = 0;
	textinput->caps_lock = 0;
	textinput->max_size = 256;
	textinput->start_display = 0;
	textinput->max_char_display = (textinput->box.width / 6) - 1;
	if (*textinput->modified_path)
		ft_strlcpy(textinput->path, *textinput->modified_path, 256);
	else
		textinput->path[0] = 0;
	textinput->size = ft_strlen(textinput->path);
}

void	init_nameinput(t_game *game, t_nameinput *nameinput)
{
	nameinput->is_selected = 0;
	nameinput->shift = 0;
	nameinput->caps_lock = 0;
	nameinput->max_size = 20;
	nameinput->start_display = 0;
	nameinput->max_char_display = (nameinput->box.width / 6) - 1;
	if (game->settings.name[0])
		ft_strlcpy(nameinput->path, game->settings.name, 20);
	else
		nameinput->path[0] = 0;
	nameinput->size = ft_strlen(nameinput->path);
}

void	reset_textinput(t_game *game, t_textinput *textinput)
{
	if (*textinput->modified_path)
		ft_strlcpy(textinput->path, *textinput->modified_path, 256);
	else
		textinput->path[0] = 0;
	textinput->size = ft_strlen(textinput->path);
	if (game)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
	}
	textinput->is_selected = 0;
	textinput->start_display = 0;
	textinput->shift = 0;
	textinput->caps_lock = 0;
}

void	reset_textinput_start(t_game *game, t_textinput *textinput)
{
	if (*textinput->modified_path)
		ft_strlcpy(textinput->path, *textinput->modified_path, 256);
	else
		textinput->path[0] = 0;
	textinput->size = ft_strlen(textinput->path);
	if (game)
	{
		game->fcts.keypressed_fct = startscreen_key_press;
		game->fcts.keyreleased_fct = startscreen_key_release;
	}
	textinput->is_selected = 0;
	textinput->start_display = 0;
	textinput->shift = 0;
	textinput->caps_lock = 0;
}

int	release_cond_textinput(t_game *game, t_textinput *textinput, int x, int y)
{
	if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= textinput->box.x
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2)
		<= textinput->box.x + textinput->box.width
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		>= textinput->box.y + game->menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		<= textinput->box.y + game->menu.scroll_amount + textinput->box.height)
		return (1);
	return (0);
}

int	release_cond_nameinput(t_game *game, t_nameinput *textinput, int x, int y)
{
	if (x - (WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) >= textinput->box.x
		&& x - (WIN_WIDTH / 2 - ENDMENU_WIDTH / 2)
		<= textinput->box.x + textinput->box.width
		&& y - (WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2)
		>= textinput->box.y + game->end_menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2)
		<= textinput->box.y + game->end_menu.scroll_amount + textinput->box.height)
		return (1);
	return (0);
}

int	release_cond_textinput_start(t_game *game, t_textinput *textinput,
	int x, int y)
{
	(void)game;
	if (x >= textinput->box.x
		&& x <= textinput->box.x + textinput->box.width
		&& y >= textinput->box.y
		&& y <= textinput->box.y + textinput->box.height)
		return (1);
	return (0);
}
