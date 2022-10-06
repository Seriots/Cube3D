/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:05:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:17:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#include "mlx.h"
#include "ft.h"

#include "mzg_incs_bonus.h"

/*
* Parmaeters:
* 1. map: a non allocated pointer of 2D array of chars
* 2. width: max width of the map
* 3. height: max height of the map
*
* Return value:
* 0: success
* 1: failure
* and the map is filled with the maze
*
* Description:
* This function generates a maze and fills the map with it.
* This generate a maze with the height as fixed value and with a variable width.
* you can use different fonction to clean the maze at the end.
* (no diago, no alone, only_alone) in the fill mzg_clean.c
*/

int	gen_maze(char ***map, int width, int height)
{
	int		i;

	(*map) = ft_calloc(sizeof(char *), height + 1);
	if (!(*map))
		return (1);
	i = 0;
	while (i < height)
	{
		(*map)[i] = ft_calloc(sizeof(char), width + 1);
		if (!(*map)[i])
			return (ft_free_tab((*map)), 1);
		i++;
	}
	makeshape_maze((*map), width, height);
	fillmap((*map));
	make_maze((*map), width, height);
	standardize_maze((*map), width, height);
	clean_maze((*map), width, height);
	post_player((*map), width, height);
	return (0);
}
