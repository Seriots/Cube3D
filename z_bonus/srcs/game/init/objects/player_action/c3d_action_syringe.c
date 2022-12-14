/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_syringe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:45:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

int	syringe_use(t_game *game, t_dict *dict, t_object *obj)
{
	game->player.max_stamina += 10;
	obj->delete(game, dict, obj);
	game->player.stats.use_object.value += 1;
	return (0);
}

int	syringe_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	drop_items(game, &game->inventory, obj);
	return (0);
}

int	syringe_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	add_items(game, &game->inventory, obj);
	return (0);
}
