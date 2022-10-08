/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_seed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:21:16 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 23:20:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "c3d_startscreen.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

int	seed_keypress(KeySym key, t_game *game)
{
	t_seed	*seed;
	int		keyint;

	seed = dict_getelem_number(game->start_menu.all_objects, 3)->value;
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

	seed = dict_getelem_number(game->start_menu.all_objects, 3)->value;
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
	seed = dict_getelem_number(game->start_menu.all_objects, 3)->value;
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

t_dict	*init_seed(t_game *game)
{
	t_seed	*seed;
	t_dict	*obj;

	seed = malloc(sizeof(t_seed));
	if (!seed)
		return (0);
	seed->box.height = 24;
	seed->box.width = 200;
	seed->box.x = 1000;
	seed->box.y = WIN_HEIGHT - 100;
	seed->box.x_text = seed->box.x - 50;
	seed->box.y_text = seed->box.y + 16;
	ft_strlcpy(seed->box.font, FONT, ft_strlen(FONT));
	ft_strlcpy(seed->box.description, "Seed", 5);
	seed->box.mouse_press = seed_press;
	seed->box.mouse_release = NULL;
	seed->is_selected = 0;
	seed->modified_value = &(game->settings.seed);
	seed->tmp_value = *seed->modified_value;
	obj = dict_new(SEED, seed);
	if (!obj)
		return (free(seed), (void *)0);
	return (obj);
}
