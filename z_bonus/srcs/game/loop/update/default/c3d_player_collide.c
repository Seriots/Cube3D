/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_player_collide.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:42:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/30 13:38:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

int	get_new_wall(t_game *game, t_vector player, t_wall *wall, int i)
{
	wall->face = 0;
	wall->dist = 0;
	wall->dist_from_start = 0;
	intersect_wall(game, player, wall, i);
	return (0);
}

double	corner_coll(t_game *game, t_coord *mov)
{
	int	i;
	int	j;
	int	k;
	t_point	point;	
	double	x;
	double	y;

	i = (mov->x + game->player.pos.x) / CASE_SIZE;
	j = (mov->y + game->player.pos.y) / CASE_SIZE;
	x = mov->x + game->player.pos.x - i * CASE_SIZE;
	y = (mov->y + game->player.pos.y) - j * CASE_SIZE;
	k = -1;
	while (++k < 4)
	{
		point.x = k % 2;
		point.y = k / 2;
		if (x > point.x * CASE_SIZE - point.x * (CASE_SIZE / 4) && x < CASE_SIZE * point.x + (1 - point.x) * CASE_SIZE / 4
			&& y > point.y * CASE_SIZE - point.y * (CASE_SIZE / 4) && y < CASE_SIZE * point.y + (1 - point.y) * CASE_SIZE / 4)
		{
			if ((game->map.map[j + point.y - (1 - point.y)][i + point.x - (1 - point.x)] == '1'
				|| (game->map.map[j + point.y - (1 - point.y)][i] == '1'
				|| game->map.map[j][i + point.x - (1 - point.x)] == '1')))
			{
				if (x - mov->x < 0 || x - mov->x > 64)
					mov->y = (CASE_SIZE / 4 + (CASE_SIZE / 2) * point.y - (y - mov->y)); 
				else if (y - mov->y < 0 || y - mov->y > 64)
					mov->x = (CASE_SIZE / 4 + (CASE_SIZE / 2) * point.x - (x - mov->x)); 
				else
				{
					if (dabs(CASE_SIZE / 4 + (CASE_SIZE / 2) * point.y - (y - mov->y))
						< dabs(CASE_SIZE / 4 + (CASE_SIZE / 2) * point.x - (x - mov->x)))
						mov->y = (CASE_SIZE / 4 + (CASE_SIZE / 2) * point.y - (y - mov->y));
					else
						mov->x = (CASE_SIZE / 4 + (CASE_SIZE / 2) * point.x - (x - mov->x));
				}
				return (1);
			}			
		}
	}
	return (0);
}

int	check_collide(t_game *game, t_coord mov)
{
	t_wall		wallh;
	t_wall		wallv;
	t_vector	player;

	if (mov.x == 0 && mov.y == 0)
		return (0);
	player.x = game->player.pos.x;
	player.y = game->player.pos.y;
	player.angle.value = M_PI_2 - sign(mov.x) * M_PI_2;
	player.angle.cos = sign(mov.x);
	player.angle.sin = 0;
	player.angle.tan = 0;
	get_new_wall(game, player, &wallh, WIN_WIDTH);
	player.angle.value = M_PI + sign(mov.y) * M_PI_2;
	player.angle.cos = 0;
	player.angle.sin = -sign(mov.y);
	player.angle.tan = player.angle.sin / player.angle.cos;
	get_new_wall(game, player, &wallv, WIN_WIDTH);
	while (corner_coll(game, &mov))
	 ;
	if (wallh.dist - CASE_SIZE / 4 < dabs(mov.x))
		mov.x = pure_sign(mov.x) * (wallh.dist - CASE_SIZE / 4);
	if (wallv.dist - CASE_SIZE / 4 < dabs(mov.y))
		mov.y = pure_sign(mov.y) * (wallv.dist - CASE_SIZE / 4);
	game->player.pos.x += mov.x;
	game->player.pos.y += mov.y;;
	return (0);
}