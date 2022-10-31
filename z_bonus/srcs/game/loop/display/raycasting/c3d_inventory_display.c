/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_inventory_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 13:18:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:43:48 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

unsigned int	get_hotbar_color(int x, int y, int is_selected)
{
	if (x < HOTBAR_BIG_BORDER
		|| x > HOTBAR_CASE_SIZE - HOTBAR_BIG_BORDER
		|| y < HOTBAR_BIG_BORDER
		|| y > HOTBAR_CASE_SIZE - HOTBAR_BIG_BORDER)
		return (0x949494);
	else if (x < HOTBAR_BIG_BORDER + HOTBAR_CASE_BORDER
		|| x > HOTBAR_CASE_SIZE - HOTBAR_BIG_BORDER - HOTBAR_CASE_BORDER
		|| y < HOTBAR_BIG_BORDER + HOTBAR_CASE_BORDER
		|| y > HOTBAR_CASE_SIZE - HOTBAR_BIG_BORDER - HOTBAR_CASE_BORDER)
		return (0xDDDDDD);
	else if (x < 2 * HOTBAR_BIG_BORDER + HOTBAR_CASE_BORDER
		|| x > HOTBAR_CASE_SIZE - 2 * HOTBAR_BIG_BORDER - HOTBAR_CASE_BORDER
		|| y < 2 * HOTBAR_BIG_BORDER + HOTBAR_CASE_BORDER
		|| y > HOTBAR_CASE_SIZE - 2 * HOTBAR_BIG_BORDER - HOTBAR_CASE_BORDER)
		return (0x949494);
	else if (is_selected)
		return (0x686898);
	else
		return (0x444444);
}

int	draw_slot(t_game *game, t_point p, t_inventory inventory, int num)
{
	int				i;
	int				j;

	i = 0;
	while (i < HOTBAR_CASE_SIZE)
	{
		j = 0;
		while (j < HOTBAR_CASE_SIZE)
		{
			my_mlx_pixel_put(&game->all_img.screen_img, p.x + i, p.y + j,
				get_hotbar_color(i, j, num == inventory.selected));
			j++;
		}
		i++;
	}
	return (0);
}

int	draw_image(t_game *game, int i, t_point p)
{
	int	x;
	int	y;

	x = p.x + HOTBAR_CASE_SIZE / 2
		- game->inventory.items[i]->menu_img->width / 2;
	y = p.y + HOTBAR_CASE_SIZE / 2
		- game->inventory.items[i]->menu_img->height / 2;
	my_mlx_put_image_to_window(game, game->inventory.items[i]->menu_img, x, y);
	return (0);
}

int	draw_hotbar(t_game *game)
{
	t_point	p;
	int		i;

	p.x = (WIN_WIDTH / 2) - ((game->inventory.size) * (HOTBAR_CASE_SIZE / 2));
	p.y = HOTBAR_Y;
	i = 0;
	while (i < game->inventory.size)
	{
		draw_slot(game, p, game->inventory, i);
		if (game->inventory.items[i] != NULL
			&& game->inventory.items[i]->menu_img != NULL)
			draw_image(game, i, p);
		p.x += HOTBAR_CASE_SIZE;
		i++;
	}
	return (0);
}

int	display_inventory(t_game *game)
{
	draw_hotbar(game);
	return (0);
}
