/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_bonushp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:51:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:52:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include <stdio.h>

int	bonushp_use(t_game *game, t_dict *dict, t_object *obj)
{
	if (game->player.max_life < 20)
	{
		game->player.max_life ++;
		obj->delete(game, dict, obj);
	}
	else if (game->player.life < game->player.max_life)
	{
		game->player.life ++;
		obj->delete(game, dict, obj);
	}
	else
		set_error_message(game, "This gonna do nothing", 2000);
	return (0);
}

int	bonushp_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	bonushp_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
