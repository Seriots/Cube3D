/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_ghost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:46:09 by lgiband          ###   ########.fr       */
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

int	ghost_collide(t_game *game, t_dict *dict, t_object *obj)
{
	int	damage;

	(void)dict;
	(void)obj;
	if (game->player.invincible_frames == 0)
	{
		damage = 1 * (1 + (game->level
					* (1 + game->settings.difficulty)) / 7);
		game->player.life -= damage;
		game->player.stats.life_loss.value += damage;
		if (game->player.life < 0)
			game->player.life = 0;
		game->player.invincible_frames = INVULNERABILITY_DURATION;
	}
	return (0);
}

int	ghost_del_update(t_game *game, t_dict *dict, t_object *obj)
{
	int			image_value;

	if (game->last_frame - obj->start_frame > obj->animation_duration)
		return (obj->delete(game, dict, obj));
	image_value = (game->last_frame - obj->start_frame)
		/ (obj->animation_duration / obj->nb_image);
	if (image_value >= obj->nb_image)
		image_value = obj->nb_image - 1;
	obj->game_img = &obj->all_img[7 + image_value];
	return (0);
}

int	ghost_update(t_game *game, t_dict *dict, t_object *obj)
{
	long int	cur_frame;
	int			image_value;

	(void)dict;
	if (obj->use_count >= obj->use_max)
	{
		obj->update = ghost_del_update;
		obj->start_frame = game->last_frame;
		obj->animation_duration = 400;
		obj->nb_image = 9;
		obj->is_collide = 0;
		game->player.stats.kill.value += 1;
		return (0);
	}
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

int	init_ghost(t_game *game, t_object **obj)
{
	ft_strlcpy((*obj)->tag, GHOST, 32);
	(*obj)->all_img = game->all_img.all_ghost_img;
	(*obj)->game_img = &game->all_img.all_ghost_img[0];
	(*obj)->menu_img = 0;
	(*obj)->hand_img = 0;
	(*obj)->width = (*obj)->game_img->width * 6 / 100;
	(*obj)->height = (*obj)->game_img->height * 6 / 100;
	(*obj)->state = 0;
	(*obj)->use_count = 0;
	(*obj)->use_max = 3000 + 100
		* game->level * (game->settings.difficulty + 1);
	(*obj)->is_visible = 1;
	(*obj)->is_collide = 1;
	(*obj)->start_frame = game->last_frame;
	(*obj)->nb_image = 7;
	(*obj)->animation_duration = GHOST_ANIM_DURATION;
	(*obj)->interact = ghost_interact;
	(*obj)->use = ghost_use;
	(*obj)->drop = ghost_drop;
	(*obj)->collide = ghost_collide;
	(*obj)->update = ghost_update;
	(*obj)->delete = ghost_delete;
	return (0);
}
