/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_incs_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:07:20 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MZG_INCS_BONUS_H
# define MZG_INCS_BONUS_H

# define MAZE_HEIGHT 30
# define MAZE_WIDTH 30
# define HEIGHT 70
# define WIDTH 70
# define X 380
# define Y 300
# define COLOR 0x88888888

# include "c3d_struct_bonus.h"

typedef struct s_shape
{
	int		start;
	int		end;
	int		nb_start;
	int		nb_end;
}		t_shape;

typedef struct s_wdestroy
{
	int		x;
	int		y;
	int		x2;
	int		y2;
}		t_wdestroy;

int	gen_maze(char ***map, int width, int height);
int	clean_maze(char **map, int width, int height);
int	is_ver_ok(char **map, int x, int y);
int	is_hor_ok(char **map, int x, int y);
int	fillmap(char **map);
int	make_maze(char **map, int width, int height);
int	makeshape_maze(char **map, int width, int height);
int	printmaze(char **map, int width, int height);
int	standardize_maze(char **map, int width, int height);
int	post_player(char **map, int width, int height);

int	get_maze(t_game *game);

#endif
