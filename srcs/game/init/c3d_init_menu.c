/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:10:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 11:09:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"
#include "c3d_menu.h"

#include "ft.h"
#include "dict.h"

int	init_menu(t_game *game)
{
	static	t_dict	*(*objs[])(t_game *game) = {init_resume_button,
		init_exit_button, init_fov_slidebar, init_color_checkbox};
	t_dict	*elem;
	long unsigned int		i;
	
	i = 0;
	while (i < sizeof(objs) / sizeof(objs[0]))
	{
		elem = objs[i](game);
		if (!elem)
			return (0);
		dict_add_back(&game->menu.all_objects, elem);
		i++;
	}
	return (0);
}