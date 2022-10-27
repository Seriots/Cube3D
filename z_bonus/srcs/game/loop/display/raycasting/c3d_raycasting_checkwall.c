/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_checkwall.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:39:19 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 21:41:53 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

#include <math.h>

int	check_wall_test2(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	if (map->map[((int)vec.y + 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
			== '1')
		wall->face = 'N';
	if (map->map[((int)vec.y - 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
			== '1')
		wall->face = 'S';
	wall->dist_from_start = vec.x;
	if (map->map[((int)vec.y + 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
			== '2')
		if (find_door(game, ((int)vec.x) / CASE_SIZE,
				((int)vec.y + 1) / CASE_SIZE)->face == 'N')
			wall->face = 'n';
	if (map->map[((int)vec.y - 1) / CASE_SIZE][((int)vec.x) / CASE_SIZE]
			== '2')
		if (find_door(game, ((int)vec.x) / CASE_SIZE,
				((int)vec.y - 1) / CASE_SIZE)->face == 'S')
			wall->face = 's';
	return (0);
}

int	check_wall_test1(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE]
			== '1')
		wall->face = 'W';
	if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE]
			== '1')
		wall->face = 'E';
	wall->dist_from_start = vec.y;
	if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x + 1) / CASE_SIZE]
			== '2')
		if (find_door(game, ((int)vec.x + 1) / CASE_SIZE,
				((int)vec.y) / CASE_SIZE)->face == 'W')
			wall->face = 'w';
	if (map->map[((int)vec.y) / CASE_SIZE][((int)vec.x - 1) / CASE_SIZE]
			== '2')
		if (find_door(game, ((int)vec.x - 1) / CASE_SIZE,
				((int)vec.y) / CASE_SIZE)->face == 'E')
			wall->face = 'e';
	return (0);
}

int	check_wall(t_game *game, t_map *map, t_vector vec, t_wall *wall)
{
	(void)game;
	if (vec.x - (int)vec.x == 0 && (int)vec.x % CASE_SIZE == 0)
		check_wall_test1(game, map, vec, wall);
	else
		check_wall_test2(game, map, vec, wall);
	return (wall->face);
}
