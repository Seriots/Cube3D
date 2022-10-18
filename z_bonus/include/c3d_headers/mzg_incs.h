/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_incs.h                                   :+:      :+:    :+:   */
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
# define BASE "NSWE"
# define DEFAULT_IMAGE_PATH_NO "imgs/xpm/blueWall64x64.xpm"
# define DEFAULT_IMAGE_PATH_SO "imgs/xpm/redWall64x64.xpm"
# define DEFAULT_IMAGE_PATH_WE "imgs/xpm/purpleWall64x64.xpm"
# define DEFAULT_IMAGE_PATH_EA "imgs/xpm/greenWall64x64.xpm"
# define DEFAULT_IMAGE_PATH_CE "imgs/xpm/woodwall.xpm"
# define DEFAULT_IMAGE_PATH_FL "imgs/xpm/woodwall.xpm"
# define DEFAULT_CEIL	"37,37,37"
# define DEFAULT_FLOOR	"110,110,110"
# define OPEN_FACTOR 4
# include "c3d_struct.h"

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

typedef struct s_starter
{
	int		x;
	int		y;
	int		start_delay;
	int		radius;
}		t_starter;

typedef struct s_genparams
{
	unsigned long	seed;
	int				difficulty;
	int				width;
	int				height;
	int				door;
}	t_genparams;

int	gen_maze(t_game *game, int width, int height, int door);
int	clean_maze(char **map, int width, int height);
int	is_ver_ok(char **map, int x, int y);
int	is_hor_ok(char **map, int x, int y);
int	fillmap(char **map);
int	make_maze(char **map, int width, int height);
int	makeshape_maze(char **map, int width, int height);
int	printmaze(t_map *map, int width, int height);
int	standardize_maze(char **map, int width, int height);
int	standardize_maze_predoor(char **map, int width, int height);
int	post_player(char **map, int width, int height);

int	get_maze(t_game *game, t_genparams params, unsigned long *seed, int print);

/*V2*/
int	is_door(char **map, int x, int y);
int	is_aligned(char **map, int x, int y);
char	is_between_room(char **map, int x, int y);
char	is_destroyable(char **map, int x, int y);
int	make_door(char **map, int width, int height, int door);
int open_maze(char **map, int width, int height);
int generate_player(t_map *map, int width, int height);
int	generate_key(t_game *game, int width, int height, int door);

#endif
