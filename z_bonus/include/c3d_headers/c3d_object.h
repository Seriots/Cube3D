/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:13:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 13:52:41 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_OBJECT_H
# define C3D_OBJECT_H

#include "dict.h"

# define KEY "KEY"
# define DOOR "DOOR"
# define ENDOOR "ENDOOR"
# define LAMP "LAMP"
# define ENERGY "ENERGY"
# define B_ENERGY "BIG_ENERGY"
# define HEAL "HEAL"
# define FULLHEAL "FULL_HEAL"
# define BONUSHP "BONUSHP"
# define MAP "MAP"
# define GHOST "GHOST"


# define GAME 0
# define HAND 1
# define ICON 2

/*Obj*/
int	init_key(t_game *game, t_object **obj);
int	init_lamp(t_game *game, t_object **obj);
int	init_door(t_game *game, t_object **obj);
int	init_endoor(t_game *game, t_object **obj);
int	init_fullheal(t_game *game, t_object **obj);
int	init_energy(t_game *game, t_object **obj);
int	init_benergy(t_game *game, t_object **obj);
int	init_bonushp(t_game *game, t_object **obj);
int	init_heal(t_game *game, t_object **obj);
int	init_obj(t_game *game, char *tag, int x, int y);

#endif