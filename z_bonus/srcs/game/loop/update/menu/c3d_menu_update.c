/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:42:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/21 11:03:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"

#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	make_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MENU_HEIGHT)
	{
		x = 0;
		while (x < MENU_WIDTH)
		{
			if (x < BORDER_SIZE || x >= MENU_WIDTH - BORDER_SIZE
				|| y < BORDER_SIZE || y >= MENU_HEIGHT - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xAAAAAA);
			x++;
		}
		y++;
	}
	return (0);
}

int	make_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < MENU_HEIGHT)
	{
		x = 0;
		while (x < MENU_WIDTH)
		{
			if (x < BORDER_SIZE || x >= MENU_WIDTH - BORDER_SIZE
				|| y < BORDER_SIZE || y >= MENU_HEIGHT - BORDER_SIZE)
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0xDDDDDD);
			else if (y >= (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x282828);
			else
				my_mlx_pixel_put(&game->all_img.menu_img, x, y, 0x222222);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_draw_update(t_game *game, t_dict *tmp, void *value)
{
	if (ft_strcmp(tmp->key, BUTTON) == 0)
		draw_button(game, (t_button *)value);
	if (ft_strcmp(tmp->key, BUTTON2) == 0)
		draw_button_start(game, (t_button *)value);
	if (ft_strcmp(tmp->key, BUTTON3) == 0)
		draw_button_end(game, (t_button *)value);
	else if (ft_strcmp(tmp->key, SLIDEBAR) == 0)
		draw_slidebar(game, (t_slidebar *)value);
	else if (ft_strcmp(tmp->key, CHECKBOX) == 0)
		draw_checkbox(game, (t_checkbox *)value);
	else if (ft_strcmp(tmp->key, KEYINPUT) == 0)
		draw_keyinput(game, (t_keyinput *)value);
	else if (ft_strcmp(tmp->key, TEXTINPUT) == 0)
		draw_textinput(game, (t_textinput *)value);
	else if (ft_strcmp(tmp->key, NUMINPUT) == 0)
		draw_numinput(game, (t_numinput *)value);
	else if (ft_strcmp(tmp->key, MULTICHOICE) == 0)
		draw_multichoice(game, (t_multichoice *)value);
	else if (ft_strcmp(tmp->key, SEED) == 0)
		draw_seed(game, (t_seed *)value);
	else if (ft_strcmp(tmp->key, TEXTINPUT2) == 0)
		draw_textinput_start(game, (t_textinput *)value);
	else if (ft_strcmp(tmp->key, SCROLLBAR) == 0)
		draw_scrollbar(game, (t_scrollbar *)value);
	else if (ft_strcmp(tmp->key, SCROLLBAR2) == 0)
		draw_scrollbar_end(game, (t_scrollbar *)value);
	return (0);
}

int	draw_all_objects(t_game *game, t_dict *dict)
{
	t_dict	*tmp;
	void	*value;

	tmp = dict;
	while (tmp)
	{
		value = tmp->value;
		check_draw_update(game, tmp, value);
		tmp = tmp->next;
	}
	return (0);
}

int	menu_update(t_game *game)
{
	if (game->is_update == 0)
		return (0);
	make_background(game);
	draw_all_objects(game, game->menu.all_objects);
	make_border(game);
	game->is_update = 0;
	game->is_display = 1;
	return (0);
}
