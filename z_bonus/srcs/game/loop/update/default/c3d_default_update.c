/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 18:23:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_event.h"
#include "c3d_object.h"
#include "c3d_utils.h"
#include "c3d_startscreen.h"
#include "c3d_init.h"

#include "ft.h"

#include <stdlib.h>

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
	else if (game->player.stamina < game->player.max_stamina)
		game->player.stamina += (STAMINA_BASE_GAIN
				+ (game->player.stamina / game->player.max_stamina)
				* STAMINA_GAIN) * game->delay;
	if (game->player.stamina < 0)
		game->player.stamina = 0;
	if (game->player.stamina > game->player.max_stamina)
		game->player.stamina = game->player.max_stamina;
	return (0);
}

int	check_death(t_game *game)
{
	if (game->player.life == 0)
	{
		default_display(game);
		game->settings.seed = 0;
		game->player.stats.time.value = timestamp_sec(game->start_game);
		load_gameover(game);
		return (1);
	}
	return (0);
}

int	default_update(t_game *game)
{
	int	error;

	refresh_mouse_move(game);
	error = spawn_ennemies(game);
	if (error)
		return (free_map(&game->map),
			free_textures(game, &game->all_img),
			load_startscreen(game), display_error(error));
	update_stamina(game);
	update_player(game);
	update_objects(game, game->map.all_objects);
	check_collisions_objects(game, game->map.all_objects);
	update_minimap(game);
	kill_ennemies(game);
	check_death(game);
	return (0);
}
