/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_incs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:07:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 10:52:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MZG_INCS_H
# define MZG_INCS_H

# define MAZE_HEIGHT 30
# define MAZE_WIDTH 30
# define HEIGHT 70
# define WIDTH 70
# define X 380
# define Y 300
# define COLOR 0x88888888

# include "c3d_struct.h"

typedef struct s_shape
{
	int		start;
	int		end;
	int		nb_start;
	int		nb_end;
}		t_shape;

int	gen_maze(char ***map, int width, int height);
int	clean_maze(char **map, int width, int height);
int	fillmap(char **map);
int	make_maze(char **map, int width, int height);
int	makeshape_maze(char **map, int width, int height);
int	printmaze(char **map, int width, int height);
int	standardize_maze(char **map, int width, int height);
int	post_player(char **map, int width, int height);

int	get_maze(t_game *game);

#endif
