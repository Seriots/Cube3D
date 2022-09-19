/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:56:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 17:05:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

int	check_elements(t_map *map)
{
	if (!map->NO || !map->SO || !map->WE || !map->EA)
		return (6);
	if (map->F == -1 || map->C == -1)
		return (6);
}

/*
* check if the map is surrounded by walls
* check if the hace only one player
*/

int	check_map(t_map *map)
{
	int	error;

	error = check_elements(map);
	if (error)
		return (error);
	return (0);
}