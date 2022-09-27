/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 11:49:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#include "c3d_struct.h"

#include "mzg_incs.h"

int	get_maze(t_game *game)
{
	char	**map;

	srand(time(NULL) * getpid());
	gen_maze(&map, MAZE_WIDTH, MAZE_HEIGHT);
	printmaze(map, MAZE_WIDTH, MAZE_HEIGHT); //pas vraiment
	/*Need to free game into init game again with the new map, and the new player settings*/
	return (0);
}
