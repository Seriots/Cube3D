/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:13:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 13:18:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_OBJECT_H
# define C3D_OBJECT_H

# include "dict.h"

# define KEY "KEY"
# define DOOR "DOOR"
# define ENDOOR "ENDOOR"
# define LAMP "LAMP"
# define HEAL "HEAL"
# define ENERGY "ENERGY"
# define BONUSHP "BONUSHP"
# define B_ENERGY "BIG_ENERGY"
# define FULLHEAL "FULL_HEAL"
# define MAP "MAP"
# define SYRINGE "SYRINGE"
# define GHOST "GHOST"

# define GAME 0
# define HAND 1
# define ICON 2

/*Ghost*/
# define GHOST_SPEED 0.05
# define GHOST_DMG 1
# define GHOST_NB_IMG 9
# define GHOST_ANIM_DURATION 1000

/*PLayer*/
# define INVULNERABILITY_DURATION 500

/*Player action*/
int		benergy_use(t_game *game, t_dict *dict, t_object *obj);
int		benergy_drop(t_game *game, t_dict *dict, t_object *obj);
int		benergy_interact(t_game *game, t_dict *dict, t_object *obj);
int		bonushp_use(t_game *game, t_dict *dict, t_object *obj);
int		bonushp_drop(t_game *game, t_dict *dict, t_object *obj);
int		bonushp_interact(t_game *game, t_dict *dict, t_object *obj);
int		door_use(t_game *game, t_dict *dict, t_object *obj);
int		door_drop(t_game *game, t_dict *dict, t_object *obj);
int		door_interact(t_game *game, t_dict *dict, t_object *obj);
int		endoor_use(t_game *game, t_dict *dict, t_object *obj);
int		endoor_drop(t_game *game, t_dict *dict, t_object *obj);
int		endoor_interact(t_game *game, t_dict *dict, t_object *obj);
int		energy_use(t_game *game, t_dict *dict, t_object *obj);
int		energy_drop(t_game *game, t_dict *dict, t_object *obj);
int		energy_interact(t_game *game, t_dict *dict, t_object *obj);
int		fullheal_use(t_game *game, t_dict *dict, t_object *obj);
int		fullheal_drop(t_game *game, t_dict *dict, t_object *obj);
int		fullheal_interact(t_game *game, t_dict *dict, t_object *obj);
int		ghost_use(t_game *game, t_dict *dict, t_object *obj);
int		ghost_drop(t_game *game, t_dict *dict, t_object *obj);
int		ghost_interact(t_game *game, t_dict *dict, t_object *obj);
int		heal_use(t_game *game, t_dict *dict, t_object *obj);
int		heal_drop(t_game *game, t_dict *dict, t_object *obj);
int		heal_interact(t_game *game, t_dict *dict, t_object *obj);
int		key_use(t_game *game, t_dict *dict, t_object *obj);
int		key_drop(t_game *game, t_dict *dict, t_object *obj);
int		key_interact(t_game *game, t_dict *dict, t_object *obj);
int		lamp_use(t_game *game, t_dict *dict, t_object *obj);
int		lamp_drop(t_game *game, t_dict *dict, t_object *obj);
int		lamp_interact(t_game *game, t_dict *dict, t_object *obj);
int		omap_use(t_game *game, t_dict *dict, t_object *obj);
int		omap_drop(t_game *game, t_dict *dict, t_object *obj);
int		omap_interact(t_game *game, t_dict *dict, t_object *obj);
int		syringe_interact(t_game *game, t_dict *dict, t_object *obj);
int		syringe_drop(t_game *game, t_dict *dict, t_object *obj);
int		syringe_use(t_game *game, t_dict *dict, t_object *obj);

/*Obj*/
int		init_ghost(t_game *game, t_object **obj);
int		init_key(t_game *game, t_object **obj);
int		init_lamp(t_game *game, t_object **obj);
int		init_door(t_game *game, t_object **obj);
int		init_endoor(t_game *game, t_object **obj);
int		init_fullheal(t_game *game, t_object **obj);
int		init_energy(t_game *game, t_object **obj);
int		init_benergy(t_game *game, t_object **obj);
int		init_bonushp(t_game *game, t_object **obj);
int		init_heal(t_game *game, t_object **obj);
int		init_omap(t_game *game, t_object **obj);
int		init_syringe(t_game *game, t_object **obj);
int		init_obj(t_game *game, char *tag, int x, int y);

/*Utils*/
int		move_ghost(t_game *game, t_object *obj);
t_dict	*get_nearest_door(t_game *game, t_dict **all_obj);

#endif
