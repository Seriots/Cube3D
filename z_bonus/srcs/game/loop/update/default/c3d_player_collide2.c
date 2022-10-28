/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:19:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/28 12:20:21 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

#include <stdio.h>

int	check_collide(t_game *game, t_coord mov)
{
	if (mov.x == 0 && mov.y == 0)
		return (0);
}