/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_textinput.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

static char	*get_reduce_path(char path[256], t_textinput *textinput)
{
	if (textinput->size < textinput->max_char_display)
		return (textinput->path);
	else if (textinput->size - textinput->start_display
		< textinput->max_char_display)
		ft_strlcpy(path, &textinput->path[textinput->size
			- textinput->max_char_display], textinput->max_char_display + 1);
	else
	{
		ft_strlcpy(path, &textinput->path[textinput->start_display],
			textinput->max_char_display + 1 - 3);
		ft_strlcat(path, "...", textinput->max_char_display + 1);
	}
	return (path);
}

int	display_textinput_text(t_game *game, t_textinput *textinput)
{
	char	path[256];

	path[0] = 0;
	if (textinput->box.y_text + game->menu.scroll_amount >= 9
		&& textinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + textinput->box.x_text,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
			+ textinput->box.y_text + game->menu.scroll_amount,
			0xAAAAAA, textinput->box.description);
	if (textinput->box.y_text + game->menu.scroll_amount >= 9
		&& textinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + textinput->box.x + 2,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
			+ textinput->box.y_text + game->menu.scroll_amount,
			0xAAAAAA, get_reduce_path(path, textinput));
	return (0);
}
