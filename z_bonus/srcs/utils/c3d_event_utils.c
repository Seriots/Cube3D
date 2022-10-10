/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:13:22 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 16:16:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

int	press_collide_cond(t_game *game, int x, int y, t_dict *tmp)
{
	t_collide_box	*box;

	box = tmp->value;
	if (ft_strcmp(tmp->key, SCROLLBAR) != 0
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
