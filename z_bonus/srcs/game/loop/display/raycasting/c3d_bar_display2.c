/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_bar_display2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:27:32 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 13:28:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

int	choose_color_lightbar(t_game *game, int x, int y, int limit)
{
	(void)game;
	if (x == 0 || x == BAR_WIDTH - 1 || y == 0 || y == BAR_HEIGHT - 1)
		return (0x222222);
	if (x < limit)
		return (0xFFBD25);
	else
		return (0xDDDDDD);
	return (0);
}

int	display_lightbar(t_game *game, t_object *obj)
{
	int		i;
	int		j;
	int		value;

	value = (obj->use_count * 100 / obj->use_max) * BAR_WIDTH / 100;
	i = 0;
	my_mlx_put_image_to_window(game, &game->all_img.hud[2], 10, 100);
	while (i < BAR_HEIGHT)
	{
		j = 0;
		while (j < BAR_WIDTH)
		{
			my_mlx_pixel_put(&game->all_img.screen_img, 40 + j, 100 + i,
				choose_color_lightbar(game, j, i, value));
			j++;
		}
		i++;
	}
	return (0);
}
