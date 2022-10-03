/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_slidebar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:54:16 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 15:04:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"
#include "ft.h"

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
