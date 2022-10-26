/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_ennemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:11:05 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/26 12:56:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_object.h"
#include "c3d_utils.h"
#include "c3d_loop.h"

#include "ft.h"

#include <stdlib.h>

#include <stdio.h>

int	nb_ghost(t_dict *all_obj)
{
	int		count;
	t_dict	*tmp;

	count = 0;
	tmp = all_obj;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, GHOST))
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int	do_spawn(t_game *game, int i, int is_spawn, t_point p)
{
	int	error;

	if (is_spawn + (game->level * 6) + (game->settings.difficulty * game->level)
		> 4980 && nb_ghost(game->map.all_objects) < 12)
	{
		while (1)
		{
			p.x = rand() % game->map.width * CASE_SIZE;
			p.y = rand() % game->map.height * CASE_SIZE;
			if (norm(p.x - game->player.pos.x, p.y - game->player.pos.y)
				> 1000 || i > 100)
				break ;
			i++;
		}
		if (i > 100)
			return (0);
		error = init_obj(game, GHOST, p.x, p.y);
		if (error)
			return (error);
	}
	return (0);
}

int	spawn_ennemies(t_game *game)
{
	t_point	p;
	int		is_spawn;
	int		i;
	int		j;
	int		error;

	j = 0;
	while (j < game->delay / 20)
	{
		is_spawn = rand() % 5000;
		i = 0;
		error = do_spawn(game, i, is_spawn, p);
		if (error)
			return (error);
		j++;
	}
	return (0);
}

int	take_damage(t_game *game, t_object *obj, double angle)
{
	double	dist;
	float	damage;

	dist = dist_to_obj(game->player.pos, obj->pos);
	damage = game->player.damage + ((15 - ((angle * 15))) * (750 - dist) / 75) / 2;
	if (damage < 0 || 1000 - dist < 0)
		damage = 0;
	obj->use_count += damage * game->delay / 50;
	return (0);
}

int	kill_ennemies(t_game *game)
{
	t_dict		*tmp;
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
