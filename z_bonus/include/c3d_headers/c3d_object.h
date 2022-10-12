/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_object.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:13:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 11:23:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_OBJECT_H
# define C3D_OBJECT_H

#include "dict.h"

# define KEY "KEY"

/*Key*/
int	init_key(t_game *game, t_object **obj);

/*Obj*/
int	init_obj(t_game *game, char *tag, int x, int y);

#endif