/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_action_ghost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:04:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/18 23:54:08 by lgiband          ###   ########.fr       */
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

int	ghost_interact(t_game *game, t_dict *dict, t_object *obj)
{
	(void)dict;
	(void)obj;
	(void)game;
	return (0);
}
