/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_keyinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:19 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 22:17:33 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"

static char	get_maj_char(KeySym key)
{
	if (key >= 'a' && key <= 'z')
		return (key - 32);
	return (key);
}

int	display_keyinput_text(t_game *game, t_keyinput *keyinput)
{
	char	buf[2];

	if (keyinput->box.y_text + game->menu.scroll_amount >= 9
		&& keyinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x_text,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
			+ keyinput->box.y_text + game->menu.scroll_amount,
			0xAAAAAA, keyinput->box.description);
	buf[1] = 0;
	buf[0] = get_maj_char(*keyinput->modified_value);
	if (keyinput->box.y_text + game->menu.scroll_amount >= 9
		&& keyinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x
			+ (keyinput->box.width / 2) - 2,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + keyinput->box.y_text
			+ game->menu.scroll_amount,
			keyinput->color, buf);
	return (0);
}
