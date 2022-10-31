/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_bar_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:25:11 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:43:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"

int	choose_color_stamina(t_game *game, int x, int y, int limit)
{
	(void)game;
	if (x == 0 || x == BAR_WIDTH - 1 || y == 0 || y == BAR_HEIGHT - 1)
		return (0x222222);
	if (x < limit)
		return (0x2F9DFE);
	else
		return (0xDDDDDD);
	return (0);
}

int	display_staminabar(t_game *game)
{
	int		i;
	int		j;
	int		value;

	value = (game->player.stamina * 100 / game->player.max_stamina)
		* BAR_WIDTH / 100;
	my_mlx_put_image_to_window(game, &game->all_img.hud[0], 10, 20);
	i = 0;
	while (i < BAR_HEIGHT)
	{
		j = 0;
		while (j < BAR_WIDTH)
		{
			my_mlx_pixel_put(&game->all_img.screen_img, 40 + j, 20 + i,
				choose_color_stamina(game, j, i, value));
			j++;
		}
		i++;
	}
	return (0);
}

int	choose_color_life(t_game *game, int x, int y, int value)
{
	int	limit;

	if (game->player.max_life == 0)
		return (0);
	if (value == game->player.max_life - 1)
		limit = BAR_WIDTH - (BAR_WIDTH / game->player.max_life * value);
	else
		limit = (BAR_WIDTH / game->player.max_life);
	if (x == 0 || x == limit - 1 || y == 0 || y == BAR_HEIGHT - 1)
		return (0x222222);
	if (value >= game->player.life)
		return (0xDDDDDD);
	else
		return (0xF70303);
	return (0);
}

int	draw_one_hp(t_game *game, int size, int value, int start)
{
	int		i;
	int		j;

	i = 0;
	while (i < BAR_HEIGHT)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(&game->all_img.screen_img, 40 + j + start, 60 + i,
				choose_color_life(game, j, i, value));
			j++;
		}
		i++;
	}
	return (0);
}

int	display_lifebar(t_game *game)
{
	int	i;
	int	size;
	int	start;

	if (game->player.max_life == 0)
		size = BAR_WIDTH;
	else
	{
		my_mlx_put_image_to_window(game, &game->all_img.hud[1], 10, 60);
		size = BAR_WIDTH / game->player.max_life;
	}
	i = 0;
	start = 0;
	while (i < game->player.max_life)
	{
		if (i == game->player.max_life - 1)
			size = BAR_WIDTH - (size * i);
		draw_one_hp(game, size, i, start);
		start += size;
		i++;
	}
	return (0);
}
