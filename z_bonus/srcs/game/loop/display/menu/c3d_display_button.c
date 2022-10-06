/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_button.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:17 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"

int	display_button_text(t_game *game, t_button *button)
{
	mlx_string_put(game->mlx.display, game->mlx.window,
		(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + button->box.x_text,
		(WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + button->box.y_text,
		0xAAAAAA, button->box.description);
	return (0);
}
