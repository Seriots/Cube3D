/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 13:32:36 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STRUCT_H
# define C3D_STRUCT_H

# include <X11/X.h>
# include <stdbool.h>

typedef struct s_game	t_game;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img_data;

typedef struct s_all_img
{
	t_img_data	no;
	t_img_data	so;
	t_img_data	we;
	t_img_data	ea;
	t_img_data	screen_img;
	t_img_data	menu_img;
}	t_all_img;	

typedef struct s_wall
{
	float			x;
	float			y;
	float			dist;
	float			angle;
	int				face;
	t_img_data		*color;
}				t_wall;

typedef struct s_settings
{
	float	fov;
	float	sensibility;
	float	fps;
	KeySym	left;
	KeySym	right;
	KeySym	forward;
	KeySym	backward;
	KeySym	turn_left;
	KeySym	turn_right;
	KeySym	pause;
}	t_settings;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
}	t_map;

typedef struct s_coord
{
	float	x;
	float	y;
}	t_coord;

typedef struct s_player
{
	t_coord			pos;
	float			rot;
	bool			forward;
	bool			backward;
	bool			left;
	bool			right;
	bool			turn_left;
	bool			turn_right;
}	t_player;

typedef struct s_mlx
{
	void		*display;
	void		*window;
}	t_mlx;

typedef struct s_fct
{
	int	(*update_fct)(t_game *game);
	int	(*display_fct)(t_game *game);
	int	(*keypressed_fct)(KeySym key, t_game *game);
	int	(*keyreleased_fct)(KeySym key, t_game *game);
	int	(*mousepressed_fct)(int button, int x, int y, t_game *game);
	int	(*mousereleased_fct)(int button, int x, int y, t_game *game);
	int	(*mousemove_fct)(int x, int y, t_game *game);
}	t_fct;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_all_img	all_img;
	t_fct		fcts;
	t_settings	settings;
}	t_game;

#endif
