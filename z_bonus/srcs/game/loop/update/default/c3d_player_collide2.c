/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 08:58:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:59:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

int	is_in_corner(t_coord movpos, int k)
{
	if (movpos.x > (k % 2) * CASE_SIZE - (k % 2) * (CASE_SIZE / 4)
		&& movpos.x < CASE_SIZE * (k % 2) + (1 - (k % 2)) * CASE_SIZE / 4
		&& movpos.y > (k / 2) * CASE_SIZE - (k / 2) * (CASE_SIZE / 4)
		&& movpos.y < CASE_SIZE * (k / 2) + (1 - (k / 2)) * CASE_SIZE / 4)
		return (1);
	return (0);
}

int	is_a_corner(t_game *game, t_point casepos, int k)
{
	if (game->map.map[casepos.y + (k / 2) - (1 - (k / 2))]
		[casepos.x + (k % 2) - (1 - (k % 2))] == '1'
		|| game->map.map[casepos.y + (k / 2) - (1 - (k / 2))]
		[casepos.x] == '1'
		|| game->map.map[casepos.y]
		[casepos.x + (k % 2) - (1 - (k % 2))] == '1')
		return (1);
	return (0);
}

int	corner_move(t_coord *mov, t_coord movpos, int k)
{
	if (movpos.x - mov->x < 0 || movpos.x - mov->x > 64)
		mov->y = (CASE_SIZE / 4 + (CASE_SIZE / 2)
				* (k / 2) - (movpos.y - mov->y));
	else if (movpos.y - mov->y < 0 || movpos.y - mov->y > 64)
		mov->x = (CASE_SIZE / 4 + (CASE_SIZE / 2)
				* (k % 2) - (movpos.x - mov->x));
	else
	{
		if (dabs(CASE_SIZE / 4 + (CASE_SIZE / 2)
				* (k / 2) - (movpos.y - mov->y))
			< dabs(CASE_SIZE / 4 + (CASE_SIZE / 2)
				* (k % 2) - (movpos.x - mov->x)))
			mov->y = (CASE_SIZE / 4 + (CASE_SIZE / 2)
					* (k / 2) - (movpos.y - mov->y));
		else
			mov->x = (CASE_SIZE / 4 + (CASE_SIZE / 2)
					* (k % 2) - (movpos.x - mov->x));
	}
	return (0);
}

double	corner_coll(t_game *game, t_coord *mov)
{
	int		k;
	t_point	casepos;
	t_coord	movpos;

	casepos.x = (mov->x + game->player.pos.x) / CASE_SIZE;
	casepos.y = (mov->y + game->player.pos.y) / CASE_SIZE;
	movpos.x = mov->x + game->player.pos.x - casepos.x * CASE_SIZE;
	movpos.y = (mov->y + game->player.pos.y) - casepos.y * CASE_SIZE;
	k = -1;
	while (++k < 4)
	{
		if (is_in_corner(movpos, k))
		{
			if (is_a_corner(game, casepos, k))
			{
				corner_move(mov, movpos, k);
				return (1);
			}			
		}
	}
	return (0);
}
