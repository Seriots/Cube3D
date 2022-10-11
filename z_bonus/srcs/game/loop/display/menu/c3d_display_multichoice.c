/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_multichoice.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:11:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 11:27:53 by lgiband          ###   ########.fr       */
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

	y = multichoice->box.y_text + game->menu.scroll_amount;
	mlx_string_put(game->mlx.display, game->mlx.window, multichoice->box.x_text,
		y, 0xAAAAAA, multichoice->box.description);
	mlx_string_put(game->mlx.display, game->mlx.window, multichoice->box.x
		+ multichoice->box.width / 2
		- (FONT_WIDTH * ft_strlen(multichoice->all_values[multichoice->current])) / 2,
		y, 0xAAAAAA, multichoice->all_values[multichoice->current]);
	return (0);
}
