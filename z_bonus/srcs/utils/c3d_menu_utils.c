/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "ft.h"
#include "mlx.h"

int	clear_all_other_selected(t_game *game, void *keyinput)
{
	t_dict	*tmp;

	tmp = game->menu.all_objects;
	while (tmp)
	{
		if (tmp->value != keyinput && ft_strcmp(tmp->key, KEYINPUT) == 0)
			((t_keyinput *)tmp->value)->is_selected = 0;
		else if (tmp->value != keyinput && ft_strcmp(tmp->key, TEXTINPUT) == 0
			&& ((t_textinput *)tmp->value)->is_selected == 1)
		{
			((t_textinput *)tmp->value)->is_selected = 0;
			((t_textinput *)tmp->value)->start_display = 0;
			ft_strlcpy(((t_textinput *)tmp->value)->path,
				*((t_textinput *)tmp->value)->modified_path, 256);
			((t_textinput *)tmp->value)->size
				= ft_strlen(((t_textinput *)tmp->value)->path);
		}
		else if (tmp->value != keyinput && ft_strcmp(tmp->key, NUMINPUT) == 0
			&& ((t_numinput *)tmp->value)->is_selected != 0)
			((t_numinput *)tmp->value)->is_selected = 0;
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
			((t_keyinput *)tmp->value)->color = get_key_color(game,
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
	mlx_do_key_autorepeatoff(game->mlx.display);
	return (0);
}
