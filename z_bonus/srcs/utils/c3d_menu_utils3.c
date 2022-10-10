/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:58:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 11:37:49 by lgiband          ###   ########.fr       */
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

void	load_path(t_game *game, t_textinput *textinput, char **path)
{
	t_img_data	img_data;
	char		*new_path;
	int			error;

	error = init_xpm_image(game, &img_data, textinput->path);
	if (error)
	{
		ft_strlcpy(textinput->path, *path, 256);
		textinput->size = ft_strlen(*path);
		return ;
	}
	new_path = ft_calloc(sizeof(char), ft_strlen(textinput->path) + 1);
	if (!new_path)
	{
		ft_strlcpy(textinput->path, *path, 256);
		textinput->size = ft_strlen(*path);
		return ;
	}
	ft_strlcpy(new_path, textinput->path, ft_strlen(textinput->path) + 1);
	free(*path);
	*path = new_path;
	mlx_destroy_image(game->mlx.display, (*textinput->modified_value).img);
	*textinput->modified_value = img_data;
}

char	get_char_from_key(KeySym key, int shift, int caps)
{
	const char	base[10] = "7486293150";

	if (key >= 65429 && key <= 65438)
		return (base[key - 65429]);
	if (key < 32 || key > 126)
		return (0);
	if ((shift && caps) || (!shift && !caps))
		return (key);
	else
		return (key - 32);
}

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

void	reset_textinput(t_game *game, t_textinput *textinput)
{
	ft_strlcpy(textinput->path, *textinput->modified_path, 256);
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

int	release_cond_textinput_start(t_game *game, t_textinput *textinput, int x, int y)
{
	(void)game;
	if (x >= textinput->box.x
		&& x<= textinput->box.x + textinput->box.width
		&& y>= textinput->box.y
		&& y<= textinput->box.y + textinput->box.height)
		return (1);
	return (0);
}
