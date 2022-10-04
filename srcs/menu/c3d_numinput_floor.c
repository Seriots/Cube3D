/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_numinput_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:13:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 15:44:33 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

int	floor_keypress(KeySym key, t_game *game)
{
	t_numinput	*numinput;
	int			keyint;

	numinput = dict_getelem_number(game->menu.all_objects, 7)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288))
		delete_number(numinput);
	else if (key == XK_Return || key == XK_KP_Enter)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		numinput->is_selected = 0;
		*numinput->modified_value = numinput->red * 256 * 256
			+ numinput->green * 256 + numinput->blue;
		mlx_do_key_autorepeatoff(game->mlx.display);
	}
	else if ((key == XK_Left) && numinput->is_selected > 1)
		numinput->is_selected = numinput->is_selected - 1;
	else if ((key == XK_Right) && numinput->is_selected < 3)
		numinput->is_selected = numinput->is_selected + 1;
	else
	{
		keyint = get_number_from_key(key);
		if (keyint != -1)
			add_number(numinput, keyint);
	}
	return (0);
}

int	floor_keyrelease(KeySym key, t_game *game)
{
	t_numinput	*numinput;

	numinput = dict_getelem_number(game->menu.all_objects, 7)->value;
	if (key == XK_Escape)
	{
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		numinput->is_selected = 0;
		edit_rgb(numinput);
		mlx_do_key_autorepeatoff(game->mlx.display);
	}
	return (0);
}

int	floor_release(int button, int x, int y, t_game *game)
{
	t_numinput	*numinput;

	if (button == 1)
	{
		numinput = dict_getelem_number(game->menu.all_objects, 7)->value;
		if (numinput->press_case == get_case_clicked(game, numinput, x, y))
		{
			if (numinput->is_selected == numinput->press_case)
				numinput->is_selected = 0;
			else
				numinput->is_selected = numinput->press_case;
			if (numinput->is_selected)
			{
				game->fcts.keypressed_fct = floor_keypress;
				game->fcts.keyreleased_fct = floor_keyrelease;
				mlx_do_key_autorepeaton(game->mlx.display);
				clear_all_other_selected(game, numinput);
			}
			else
			{
				game->fcts.keypressed_fct = menu_key_press;
				game->fcts.keyreleased_fct = menu_key_release;
				numinput->is_selected = 0;
				edit_rgb(numinput);
				mlx_do_key_autorepeatoff(game->mlx.display);
			}
		}
		game->fcts.mousereleased_fct = menu_mouse_release;
	}
	return (0);
}

int	floor_press(int button, int x, int y, t_game *game)
{
	t_numinput	*numinput;

	numinput = dict_getelem_number(game->menu.all_objects, 7)->value;
	if (button == 1)
	{
		numinput->press_case = get_case_clicked(game, numinput, x, y);
		if (numinput->press_case != 0)
			game->fcts.mousereleased_fct = floor_release;
	}
	return (0);
}

t_dict	*init_numinput_floor(t_game *game)
{
	t_numinput	*numinput;
	t_dict		*obj;

	numinput = malloc(sizeof(t_numinput));
	if (!numinput)
		return (0);
	numinput->box.height = 24;
	numinput->box.width = 200;
	numinput->box.x = 100;
	numinput->box.y = 300;
	numinput->box.x_text = numinput->box.x - 80;
	numinput->box.y_text = numinput->box.y + 16;
	ft_strlcpy(numinput->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	ft_strlcpy(numinput->box.description, "Floor Color", 12);
	numinput->box.mouse_press = floor_press;
	numinput->box.mouse_release = NULL;
	numinput->is_selected = 0;
	numinput->modified_value = &game->map.f;
	edit_rgb(numinput);
	obj = dict_new(NUMINPUT, numinput);
	if (!obj)
		return (free(numinput), (void *)0);
	return (obj);
}
