/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_ghost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 20:54:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "c3d_struct.h"
#include "c3d_init.h"
#include "c3d_object.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include <stdio.h>

int	ghost_use(t_game *game, t_dict *dict, t_object *obj)
{
	(void)game;
	(void)dict;
	(void)obj;
	return (0);
}

int	ghost_drop(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	(void)obj;
	(void)game;
	return (0);
}

int	ghost_collide(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	(void)obj;
	if (game->player.invincible_frames == 0)
	{
		game->player.life -= 1 * (1 + (game->level * (1 + game->settings.difficulty)) / 7);
		if (game->player.life < 0)
			game->player.life = 0;
		game->player.invincible_frames = INVULNERABILITY_DURATION;
	}
	return (0);
}

int	move_ghost(t_game *game, t_object *obj)
{
	double	dist_x;
	double	dist_y;
	double	angle;

	dist_x = game->player.pos.x - obj->pos.x;
	dist_y = game->player.pos.y - obj->pos.y;
	angle = atan(dist_y / dist_x);
	if (dist_x < 0)
		obj->pos.x -= GHOST_SPEED * game->delay * dabs(cos(angle));
	else
		obj->pos.x += GHOST_SPEED * game->delay * dabs(cos(angle));
	if (dist_y < 0)
		obj->pos.y -= GHOST_SPEED * game->delay * dabs(sin(angle));
	else
		obj->pos.y += GHOST_SPEED * game->delay * dabs(sin(angle));
	return (0);
}

int	ghost_update(t_game *game, t_dict *dict, t_object *obj)
{
	long int	cur_frame;
	int			image_value;

	(void)dict;
	cur_frame = (game->last_frame - obj->start_frame)
		% obj->animation_duration;
	image_value = cur_frame / (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	obj->game_img = &obj->all_img[image_value];
	move_ghost(game, obj);
	return (0);
}

int	ghost_delete(t_game *game, t_dict *dict, t_object *obj)
{
	(void)obj;
	dict_delone(&game->map.all_objects, dict, 0, free);
	return (0);
}

int	ghost_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	(void)obj;
	(void)game;
	return (0);
}

int	init_ghost(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, GHOST, 32);
	(*obj)->all_img = game->all_img.all_ghost_img;
	(*obj)->game_img = &game->all_img.all_ghost_img[0];
	(*obj)->menu_img = 0;
	(*obj)->hand_img = 0;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 100;
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 1;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = GHOST_NB_IMG;
	(*obj)->animation_duration = GHOST_ANIM_DURATION;
	(*obj)->interact = ghost_interact;
	(*obj)->use = ghost_use;
	(*obj)->drop = ghost_drop;
	(*obj)->collide = ghost_collide;
	(*obj)->update = ghost_update;
	(*obj)->delete = ghost_delete;
	return (0);
}
