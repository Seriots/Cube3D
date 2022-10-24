/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 17:52:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

#include <stdio.h>

int	press_collide_cond(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	box = tmp->value;
	if (ft_strcmp(tmp->key, SCROLLBAR) != 0
		&& y < (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		+ (MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= box->x
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= box->x + box->width
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		>= box->y + game->menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		<= box->y + game->menu.scroll_amount + box->height)
		return (1);
	return (0);
}

int	press_scrollbar_cond(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	(void)game;
	box = tmp->value;
	if (ft_strcmp(tmp->key, SCROLLBAR) == 0
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= box->x
		&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= box->x + box->width
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= box->y
		&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		<= box->y + box->height)
		return (1);
	return (0);
}

int	press_collide_cond_end(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	box = tmp->value;
	if (ft_strcmp(tmp->key, SCROLLBAR) != 0
		&& y < (WIN_HEIGHT / 2 - MENU_HEIGHT / 2)
		+ (MENU_HEIGHT - (15 * MENU_HEIGHT / 100))
		&& x - (WIN_WIDTH / 2 - END_WIDTH / 2) >= box->x
		&& x - (WIN_WIDTH / 2 - END_WIDTH / 2) <= box->x + box->width
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
		>= box->y + game->end_menu.scroll_amount
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
		<= box->y + game->end_menu.scroll_amount + box->height)
		return (1);
	return (0);
}

int	press_scrollbar_cond_end(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	(void)game;
	box = tmp->value;
	if (ft_strcmp(tmp->key, SCROLLBAR) == 0
		&& x - (WIN_WIDTH / 2 - END_WIDTH / 2) >= box->x
		&& x - (WIN_WIDTH / 2 - END_WIDTH / 2) <= box->x + box->width
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2) >= box->y
		&& y - (WIN_HEIGHT / 2 - END_HEIGHT / 2)
		<= box->y + box->height)
		return (1);
	return (0);
}

int	move_slot(KeySym keycode, t_game *game)
{
	int	value;

	if (keycode == game->settings.slot1)
		value = 0;
	else if (keycode == game->settings.slot2)
		value = 1;
	else if (keycode == game->settings.slot3)
		value = 2;
	else if (keycode == game->settings.slot4)
		value = 3;
	else if (keycode == game->settings.slot5)
		value = 4;
	else if (keycode == game->settings.slot6)
		value = 5;
	else if (keycode == game->settings.slot7)
		value = 6;
	else if (keycode == game->settings.slot8)
		value = 7;
	else
		return (0);
	if (value > game->inventory.size - 1)
		return (0);
	else
		game->inventory.selected = value;
	return (0);
}
