/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_checkbox.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:14 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:15:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_settings_bonus.h"

#include "mlx.h"

int	display_checkbox_text(t_game *game, t_checkbox *checkbox)
{
	if (checkbox->box.y_text + game->menu.scroll_amount >= 9
		&& checkbox->box.y_text + game->menu.scroll_amount
		< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + checkbox->box.x_text,
			(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2)
			+ checkbox->box.y_text + game->menu.scroll_amount,
			0xAAAAAA, checkbox->box.description);
	return (0);
}
