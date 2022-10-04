/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:57:29 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 15:41:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include <X11/keysym.h>

int	delete_number(t_numinput *numinput)
{
	int	*value;

	if (numinput->is_selected == 1)
		value = &numinput->red;
	if (numinput->is_selected == 2)
		value = &numinput->green;
	if (numinput->is_selected == 3)
		value = &numinput->blue;
	if (*value > 0)
		*value = *value / 10;
	return (0);
}

int	add_number(t_numinput *numinput, int n)
{
	int	*value;

	if (numinput->is_selected == 1)
		value = &numinput->red;
	if (numinput->is_selected == 2)
		value = &numinput->green;
	if (numinput->is_selected == 3)
		value = &numinput->blue;
	if (*value * 10 + n < 256)
		*value = *value * 10 + n;
	return (0);
}

int	get_number_from_key(KeySym key)
{
	const int	tab[10] = {7, 4, 8, 6, 2, 9, 3, 1, 5, 0};

	if (key >= XK_0 && key <= XK_9)
		return (key - XK_0);
	else if (key >= XK_KP_0 - 27 && key <= XK_KP_9 - 27)
		return (tab[key + 27 - XK_KP_0]);
	return (-1);
}

int	edit_rgb(t_numinput *numinput)
{
	numinput->red = (int)(*numinput->modified_value / (256 * 256)) % 256;
	numinput->green = (int)(*numinput->modified_value / (256)) % 256;
	numinput->blue = (int)(*numinput->modified_value) % 256;
	return (0);
}

int	get_case_clicked(t_game *game, t_numinput *numinput, int x, int y)
{
	(void)game;
	x -= (WIN_WIDTH / 2 - MENU_WIDTH / 2);
	y -= (WIN_HEIGHT / 2 - MENU_HEIGHT / 2);
	if (x >= numinput->box.x && x <= numinput->box.x + numinput->box.width / 4
		&& y >= numinput->box.y + game->menu.scroll_amount
		&& y <= numinput->box.y + game->menu.scroll_amount + numinput->box.height)
		return (1);
	else if (x >= numinput->box.x + (3 * (numinput->box.width / 8))
		&& x <= numinput->box.x + (5 * numinput->box.width / 8)
		&& y >= numinput->box.y + game->menu.scroll_amount
		&& y <= numinput->box.y + game->menu.scroll_amount + numinput->box.height)
		return (2);
	else if (x >= numinput->box.x + (3 * (numinput->box.width / 4))
		&& x <= numinput->box.x + numinput->box.width
		&& y >= numinput->box.y + game->menu.scroll_amount
		&& y <= numinput->box.y + game->menu.scroll_amount + numinput->box.height)
		return (3);
	else
		return (0);
}
