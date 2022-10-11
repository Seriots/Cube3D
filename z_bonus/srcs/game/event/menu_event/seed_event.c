/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seed_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:18:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 11:19:46 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"

int	seed_keypress(KeySym key, t_game *game)
{
	t_seed	*seed;
	int		keyint;

	seed = dict_getelem_number(game->start_menu.all_objects, game->pick_obj)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288))
		seed->tmp_value /= 10;
	else if (key == XK_Return || key == XK_KP_Enter)
	{
		*seed->modified_value = seed->tmp_value;
		seed->is_selected = 0;
		game->fcts.keypressed_fct = startscreen_key_press;
		game->fcts.keyreleased_fct = startscreen_key_release;
	}
	else
	{
		keyint = get_number_from_key(key);
		if (keyint != -1)
			add_number_seed(seed, keyint);
	}
	return (0);
}

int	seed_keyrelease(KeySym key, t_game *game)
{
	t_seed	*seed;

	seed = dict_getelem_number(game->start_menu.all_objects, game->pick_obj)->value;
	if (key == XK_Escape)
	{	
		*seed->modified_value = seed->tmp_value;
		seed->is_selected = 0;
		game->fcts.keypressed_fct = startscreen_key_press;
		game->fcts.keyreleased_fct = startscreen_key_release;
	}
	return (0);
}

int	seed_release(int button, int x, int y, t_game *game)
{
	t_seed	*seed;

	if (button != 1)
		return (0);
	seed = dict_getelem_number(game->start_menu.all_objects, game->pick_obj)->value;
	if (x >= seed->box.x && x <= seed->box.x + seed->box.width
		&& y >= seed->box.y && y <= seed->box.y + seed->box.height)
	{
		seed->is_selected = !seed->is_selected;
		if (seed->is_selected)
		{
			game->fcts.keypressed_fct = seed_keypress;
			game->fcts.keyreleased_fct = seed_keyrelease;
			clear_all_other_selected(game, seed, game->start_menu.all_objects);
		}
		else
		{
			*seed->modified_value = seed->tmp_value;
			seed->is_selected = 0;
			game->fcts.keypressed_fct = startscreen_key_press;
			game->fcts.keyreleased_fct = startscreen_key_release;
		}
	}
	game->fcts.mousereleased_fct = startscreen_mouse_release;
	return (0);
}

int	seed_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = seed_release;
	return (0);
}
