/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 21:02:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "ft.h"
#include "mlx.h"

int	clear_all_other_selected(t_game *game, void *keyinput, t_dict *dict)
{
	t_dict	*tmp;

	(void)game;
	tmp = dict;
	while (tmp)
	{
		if (tmp->value != keyinput && ft_strcmp(tmp->key, KEYINPUT) == 0)
			((t_keyinput *)tmp->value)->is_selected = 0;
		if (tmp->value != keyinput && ft_strcmp(tmp->key, SEED) == 0)
			reset_seed((t_seed *)tmp->value);
		else if (tmp->value != keyinput && ft_strcmp(tmp->key, TEXTINPUT) == 0
			&& ((t_textinput *)tmp->value)->is_selected == 1)
			reset_textinput(0, (t_textinput *)tmp->value);
		else if (tmp->value != keyinput && ft_strcmp(tmp->key, TEXTINPUT2) == 0
			&& ((t_textinput *)tmp->value)->is_selected == 1)
			reset_textinput_start(0, (t_textinput *)tmp->value);
		else if (tmp->value != keyinput && ft_strcmp(tmp->key, NUMINPUT) == 0
			&& ((t_numinput *)tmp->value)->is_selected != 0)
			((t_numinput *)tmp->value)->is_selected = 0;
		tmp = tmp->next;
	}
	return (0);
}

int	get_key_col(t_game *game, t_menu *menu, KeySym *key)
{
	t_dict	*tmp;

	(void)game;
	tmp = menu->all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, KEYINPUT) == 0)
		{
			if (((t_keyinput *)tmp->value)->modified_value != key
				&& *((t_keyinput *)tmp->value)->modified_value == *key)
				return (0xDD0000);
		}
		tmp = tmp->next;
	}
	return (0x00DD00);
}

int	update_key_color(t_game *game, t_menu *menu)
{
	t_dict	*tmp;

	tmp = menu->all_objects;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, KEYINPUT) == 0)
			((t_keyinput *)tmp->value)->color = get_key_col(game, menu,
					((t_keyinput *)tmp->value)->modified_value);
		tmp = tmp->next;
	}
	return (0);
}

int	reset_key_event(t_game *game)
{
	game->fcts.keypressed_fct = menu_key_press;
	game->fcts.keyreleased_fct = menu_key_release;
	return (0);
}

int	reset_key_event_num(t_game *game, t_numinput *numinput)
{
	game->fcts.keypressed_fct = menu_key_press;
	game->fcts.keyreleased_fct = menu_key_release;
	numinput->is_selected = 0;
	return (0);
}
