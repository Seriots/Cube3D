/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_get_maze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 21:20:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#include "c3d_struct.h"
#include "mzg_incs.h"

#include "ft.h"

int	get_maze(t_game *game)
{
	char	**map;

	(void)game;
	srand(time(NULL) * getpid());
	gen_maze(&map, MAZE_WIDTH, MAZE_HEIGHT);
	printmaze(map, MAZE_WIDTH, MAZE_HEIGHT);
	ft_free_tab(map);
	return (0);
}
