/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 13:27:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

int	clear_all_other_selected(t_game *game, t_keyinput *keyinput)
{
	t_dict	*tmp;

	tmp = game->menu.all_objects;
	while (tmp)
	{
		if (tmp->value != keyinput && ft_strcmp(tmp->key, KEYINPUT) == 0)
			((t_keyinput *)tmp->value)->is_selected = 0;
		tmp = tmp->next;
	}
	return (0);
}

int	get_key_color(t_game *game, KeySym *key)
{
	if (&game->settings.backward != key && game->settings.backward == *key)
		return (0xDD0000);
	else if (&game->settings.forward != key && game->settings.forward == *key)
		return (0xDD0000);
	else if (&game->settings.left != key && game->settings.left == *key)
		return (0xDD0000);
	else if (&game->settings.right != key && game->settings.right == *key)
		return (0xDD0000);
	else
		return (0x00DD00);
}

int	update_key_color(t_game *game, t_menu *menu)
{
	t_dict	*tmp;

	tmp = menu->all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, KEYINPUT) == 0)
			((t_keyinput *)tmp->value)->color = get_key_color(game, ((t_keyinput *)tmp->value)->modified_value);
		tmp = tmp->next;
	}
	return (0);
}
