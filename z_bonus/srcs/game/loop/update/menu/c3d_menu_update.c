/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:42:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:42:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"

#include "ft.h"

#include "mlx.h"

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
	const t_drawobj	all[] = {{BUTTON, draw_button},
	{BUTTON2, draw_button_start}, {BUTTON3, draw_button_end},
	{SLIDEBAR, draw_slidebar}, {CHECKBOX, draw_checkbox},
	{KEYINPUT, draw_keyinput}, {TEXTINPUT, draw_textinput},
	{TEXTINPUT2, draw_textinput_start}, {NUMINPUT, draw_numinput},
	{MULTICHOICE, draw_multichoice}, {SEED, draw_seed},
	{SCROLLBAR, draw_scrollbar}, {SCROLLBAR2, draw_scrollbar_end},
	{SCROLLBAR3, draw_scrollbar_score}, {NAMEINPUT, draw_nameinput}};
	unsigned long	i;

	i = 0;
	while (i < sizeof(all) / sizeof(t_drawobj))
	{
		if (ft_strcmp(tmp->key, all[i].tag) == 0)
		{
			all[i].fct(game, value);
			return (0);
		}
		i++;
	}
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
