/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 22:07:55 by lgiband          ###   ########.fr       */
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

int	spawn_ennemies(t_game *game)
{
	int	is_spawn;
	int	x;
	int	y;
	int	i;

	is_spawn = rand() % 5000;
	i = 0;
	if (is_spawn + (game->level * 6) + (game->settings.difficulty * game->level) > 4980 / 4)
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
		default_display(game);
		game->settings.seed = 0;
		free_textures(game, &game->all_img);
		free_map(&game->map);
		load_endscreen(game);
		return (1);
	}
	return (0);
}

int	take_damage(t_game *game, t_object *obj, double angle)
{
	double	dist;
	float	damage;

	dist = dist_to_obj(game->player.pos, obj->pos);
	damage = (1 + (15 - (angle * 15))) * (1000 - dist) / 200;
	if (damage < 0)
		damage = 0;
	obj->use_count += damage;
	//printf("damage : %f\n", obj->use_count);
	return (0);
}

int	kill_ennemies(t_game *game)
{
	t_dict	*tmp;
	t_object	*obj;

	if (!is_lamp(game))
		return (0);
	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && ft_strcmp(obj->tag, GHOST) == 0
			&& is_player_facing(game, obj, 0.3))
			take_damage(game, obj, get_angle_player_obj(game, obj, 0.3));
		tmp = tmp->next;
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
	kill_ennemies(game);
	check_death(game);
	return (0);
}
