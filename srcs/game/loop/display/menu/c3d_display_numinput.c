/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_numinput.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:52:28 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 17:30:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "mlx.h"
#include "ft.h"

int	display_numinput_text(t_game *game, t_numinput *numinput)
{
	char	buf[32];
	int		y;
	
	y = (WIN_HEIGHT / 2) - (MENU_HEIGHT / 2) + numinput->box.y_text + game->menu.scroll_amount;
	if (y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= 9
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
			< (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
	{
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + numinput->box.x_text,
			y, 0xAAAAAA, numinput->box.description);
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + numinput->box.x
				+ (numinput->box.width / 8) - (ft_size_int(numinput->red) * 3),
			y, 0xAAAAAA, ft_itoa_noalloc(buf, numinput->red));
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + numinput->box.x
				+ (3 * (numinput->box.width / 4) / 2)
				+ (numinput->box.width / 8)  - (ft_size_int(numinput->green) * 3),
			y, 0xAAAAAA, ft_itoa_noalloc(buf, numinput->green));
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2) - (MENU_WIDTH / 2) + numinput->box.x
				+ (3 * (numinput->box.width / 4))
				+ (numinput->box.width / 8)  - (ft_size_int(numinput->blue) * 3),
			y, 0xAAAAAA, ft_itoa_noalloc(buf, numinput->blue));
	}
	return (0);
}
