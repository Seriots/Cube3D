/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_hand_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:52:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 15:07:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

int	display_hand(t_game *game)
{
	t_img_data	*img;
	t_object	*obj;

	if (game->inventory.selected < 0)
		return (0);
	obj = game->inventory.items[game->inventory.selected];
	if (obj == NULL)
		return (0);
	if (obj->hand_img == NULL)
		return (0);
	img = obj->hand_img;
	my_mlx_put_image_to_window(game,
		img, WIN_WIDTH - img->width - 50 + game->inventory.current_hand.x,
		WIN_HEIGHT - ((25 * img->height ) / 36) + game->inventory.current_hand.y);
	return (0);
}