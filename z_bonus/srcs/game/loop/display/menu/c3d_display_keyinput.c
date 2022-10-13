/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_keyinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:19 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 22:55:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"
#include "mlx.h"

static char	get_maj_char(KeySym key)
{
	if (key >= 'a' && key <= 'z')
		return (key - 32);
	return (key);
}

static void	display_keyinput_char(t_game *game, t_keyinput *keyinput, char *buf)
{
	if (keyinput->box.y_text + game->menu.scroll_amount >= 9
		&& keyinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x
			+ (keyinput->box.width / 2) - (FONT_WIDTH * ft_strlen(buf) / 2),
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + keyinput->box.y_text
			+ game->menu.scroll_amount + 2,
			keyinput->color, buf);
}

int	display_keyinput_text(t_game *game, t_keyinput *keyinput)
{
	char	buf[16];

	if (keyinput->box.y_text + game->menu.scroll_amount >= 9
		&& keyinput->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + keyinput->box.x_text,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
			+ keyinput->box.y_text + game->menu.scroll_amount,
			0xAAAAAA, keyinput->box.description);
	buf[1] = 0;
	if (*keyinput->modified_value == XK_Shift_L)
		ft_strlcpy(buf, "ShtL", 16);
	else if (*keyinput->modified_value == XK_Control_L)
		ft_strlcpy(buf, "CtlL", 16);
	else if (*keyinput->modified_value == XK_Caps_Lock)
		ft_strlcpy(buf, "Caps", 16);
	else if (*keyinput->modified_value == XK_Tab)
		ft_strlcpy(buf, "Tab", 16);
	else
		buf[0] = get_maj_char(*keyinput->modified_value);
	display_keyinput_char(game, keyinput, buf);
	return (0);
}
