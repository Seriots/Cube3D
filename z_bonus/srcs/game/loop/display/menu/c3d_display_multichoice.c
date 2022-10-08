/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_multichoice.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:11:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 12:21:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"
#include "ft.h"

#include <stdio.h>

int	display_multichoice_text(t_game *game, t_multichoice *multichoice)
{
	int		y;

	y = (WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
		+ multichoice->box.y_text + game->menu.scroll_amount;
	if (y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= 9
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
	{
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + multichoice->box.x_text,
			y, 0xAAAAAA, multichoice->box.description);
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + multichoice->box.x
			+ multichoice->box.width / 2
			- (6 * ft_strlen(multichoice->all_values[multichoice->current])) / 2, 
			y, 0xAAAAAA, multichoice->all_values[multichoice->current]);
	}
	return (0);
}
