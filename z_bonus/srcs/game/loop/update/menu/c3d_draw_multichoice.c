/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw_multichoice.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:54:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 22:59:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <stdlib.h>
#include <math.h>

#include <stdio.h>

static int	is_border(t_game *game, t_multichoice *box, int x, int y)
{
	if (x <= box->box.x + 3 * box->box.width / 16 + 1 || x >= box->box.x + 13 * box->box.width / 16 - 1
		|| y < box->box.y + game->menu.scroll_amount + 1
		|| y >= box->box.y + game->menu.scroll_amount + box->box.height - 1)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
	else
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x383838);
	return (0);
}

int	draw_first_triangle(t_game *game, t_multichoice *box, int x, int y)
{
	int	max;
	int	min;
	int	y_test;

	max = ((((float)(x - box->box.x) / (box->box.width / 8))) * (box->box.height / 2.0f)) + box->box.height / 2.0f;
	min = floor(box->box.height / 2.0f - ((((float)(x - box->box.x) / (box->box.width / 8))) * (box->box.height / 2.0f)));
	y_test = y - (box->box.y + game->menu.scroll_amount);
	if (y_test == min || y_test == max || x == box->box.x + box->box.width / 8)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
	else if (y_test > min && y_test <= max)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x383838);
	return (0);
}

int	draw_second_triangle(t_game *game, t_multichoice *box, int x, int y)
{
	int	max;
	int	min;
	int	y_test;

	max = (box->box.height / 2.0f) - (((float)(x - box->box.x - 7 * (box->box.width / 8)) / (box->box.width / 8))) * (box->box.height / 2.0f);
	min = -max;
	y_test = y - (box->box.y + game->menu.scroll_amount + box->box.height / 2);
	if (y_test == min || y_test == max || max == (box->box.height / 2.0f))
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0xAAAAAA);
	else if (y_test > min && y_test < max)
		my_mlx_pixel_put(&game->all_img.screen_img, x, y, 0x383838);
	return (0);
}

int	draw_multichoice(t_game *game, t_multichoice *box)
{
	int	x;
	int	y;

	y = box->box.y + game->menu.scroll_amount;
	while (y < box->box.y + game->menu.scroll_amount + box->box.height)
	{
		x = box->box.x;
		while (x < box->box.x + box->box.width)
		{
			if (x - box->box.x <= box->box.width / 8)
				draw_first_triangle(game, box, x, y);
			else if (x - box->box.x >= 7 * box->box.width / 8)
				draw_second_triangle(game, box, x, y);
			else if (x - box->box.x > 3 * box->box.width / 16
				&& x - box->box.x < 13 * box->box.width / 16)
				is_border(game, box, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
