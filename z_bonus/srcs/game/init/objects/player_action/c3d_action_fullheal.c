/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_fullheal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:49:50 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:53:56 by lgiband          ###   ########.fr       */
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

int	fullheal_use(t_game *game, t_dict *dict, t_object *obj)
{
	if (game->player.life < game->player.max_life)
	{
		game->player.life = game->player.max_life;
		obj->delete(game, dict, obj);
	}
	else
		set_error_message(game, "You are already full life", 2000);
	return (0);
}

int	fullheal_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	fullheal_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
