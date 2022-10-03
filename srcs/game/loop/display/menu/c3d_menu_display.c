/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 13:08:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	display_slidebar_text(t_game *game, t_slidebar *slidebar)
{
	char	dst[32];
	int		x;
	int		y;

	ft_itoa_noalloc(dst, *slidebar->modified_value);
	x = (WIN_WIDTH / 2) - (MENU_WIDTH / 2) + slidebar->x + slidebar->width + 10;
	y = (WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + slidebar->box.y_text;
	mlx_string_put(game->mlx.display, game->mlx.window, x, y, 0xAAAAAA, dst);
	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + slidebar->box.x_text,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + slidebar->box.y_text,
		0xAAAAAA, slidebar->box.description);
	return (0);
}

int	display_button_text(t_game *game, t_button *button)
{
	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + button->box.x_text,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + button->box.y_text,
		0xAAAAAA, button->box.description);
	return (0);
}

int	display_checkbox_text(t_game *game, t_checkbox *checkbox)
{
	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + checkbox->box.x_text,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + checkbox->box.y_text,
		0xAAAAAA, checkbox->box.description);
	return (0);
}

static char	get_maj_char(KeySym key)
{
	if (key >= 'a' && key <= 'z')
		return (key - 32);
	return (key);
}

int	display_keyinput_text(t_game *game, t_keyinput *keyinput)
{
	char	buf[2];

	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x_text,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + keyinput->box.y_text,
		0xAAAAAA, keyinput->box.description);
	buf[1] = 0;
	buf[0] = get_maj_char(*keyinput->modified_value);
	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x + (keyinput->box.width / 2) - 2,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + keyinput->box.y + (keyinput->box.height / 2) + 5,
		keyinput->color, buf);
	return (0);
}

int	display_text(t_game *game)
{
	t_dict			*tmp;

	tmp = game->menu.all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, BUTTON) == 0)
			display_button_text(game, (t_button *)tmp->value);
		else if (ft_strcmp(tmp->key, SLIDEBAR) == 0)
			display_slidebar_text(game, (t_slidebar *)tmp->value);
		else if (ft_strcmp(tmp->key, CHECKBOX) == 0)
			display_checkbox_text(game, (t_checkbox *)tmp->value);
		else if (ft_strcmp(tmp->key, KEYINPUT) == 0)
			display_keyinput_text(game, (t_keyinput *)tmp->value);
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
