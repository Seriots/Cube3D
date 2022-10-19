/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 23:37:10 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_event.h"
#include "c3d_object.h"
#include "c3d_utils.h"
#include "c3d_startscreen.h"
#include "c3d_init.h"

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
	else if (game->player.stamina < 100)
		game->player.stamina += (STAMINA_BASE_GAIN
				+ (game->player.stamina / game->player.max_stamina)
				* STAMINA_GAIN) * game->delay;
	if (game->player.stamina < 0)
		game->player.stamina = 0;
	if (game->player.stamina > 100)
		game->player.stamina = 100;
	return (0);
}

static int	spawn_ennemies(t_game *game)
{
	int	is_spawn;
	int	x;
	int	y;
	int	i;

	is_spawn = rand() % 5000;
	i = 0;
	if (is_spawn + (game->level * 6) + (game->settings.difficulty * game->level) > 4980)
	{
		while (1)
		{
			x = rand() % game->map.width * CASE_SIZE;
			y = rand() % game->map.height * CASE_SIZE;
			if (norm(x - game->player.pos.x, y - game->player.pos.y) > 1000 || i > 100)
				break ;
			i++;
		}
		if (i > 100)
			return (0);
		init_obj(game, GHOST, x, y);
		printf("ennemy spawn\n");
	}
	return (0);
}

int	check_death(t_game *game)
{
	if (game->player.life == 0)
	{
		game->settings.seed = 0;
		free_textures(game, &game->all_img);
		free_map(&game->map);
		load_startscreen(game);
	}
	return (0);
}

int	default_update(t_game *game)
{
	refresh_mouse_move(game);
	spawn_ennemies(game);
	update_stamina(game);
	update_player(game);
	update_objects(game, game->map.all_objects);
	check_collisions_objects(game, game->map.all_objects);
	update_minimap(game);
	check_death(game);
	return (0);
}
