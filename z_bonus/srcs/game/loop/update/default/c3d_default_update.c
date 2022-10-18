/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 14:05:31 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_event.h"

#include <stdio.h>

static int	refresh_mouse_move(t_game *game)
{
	static int	i;

	if (i == 100)
		game->fcts.mousemove_fct = NULL;
	if (i == 101)
	{
		i = 0;
		game->fcts.mousemove_fct = default_mouse_move;
	}
	i++;
	return (0);
}

static int	update_stamina(t_game *game)
{
	if (game->player.run && (game->player.right
		|| game->player.left || game->player.forward
		|| game->player.backward)
			&& game->player.stamina > 0)
		game->player.stamina -= game->delay * STAMINA_LOSS;
	else if (game->player.stamina < 100)
		game->player.stamina += (STAMINA_BASE_GAIN + (game->player.stamina / game->player.max_stamina) * STAMINA_GAIN) * game->delay;
	if (game->player.stamina < 0)
		game->player.stamina = 0;
	if (game->player.stamina > 100)
		game->player.stamina = 100;
	return (0);
}

int	default_update(t_game *game)
{
	refresh_mouse_move(game);
	update_stamina(game);
	update_player(game);
	update_objects(game, game->map.all_objects);
	update_minimap(game);
	return (0);
}
