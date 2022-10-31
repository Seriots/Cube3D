/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_seed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:21:16 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:41:46 by lgiband          ###   ########.fr       */
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
#include "c3d_event.h"

#include "ft.h"
#include "mlx.h"

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
