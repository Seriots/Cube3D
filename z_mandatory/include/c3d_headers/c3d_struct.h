/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 12:16:07 by lgiband          ###   ########.fr       */
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
	t_img_data	minimap_img;
	t_img_data	*all_cursor_img;
}	t_all_img;	

typedef struct s_wall
{
	double			dist;
	double			dist_from_start;
	char			face;
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
	double	x;
	double	y;
}	t_coord;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_display
{
	int			min;
	int			max;
	double		d;
	double		angle;
	t_img_data	*img;
	int			x;
}	t_display;

typedef struct s_vector
{
	double	x;
	double	y;
	double	angle;
}	t_vector;

typedef struct s_player
{
	t_coord			pos;
	double			rot;
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
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
	int	(*keypressed_fct)(unsigned long key, t_game *game);
	int	(*keyreleased_fct)(unsigned long key, t_game *game);
}	t_fct;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_all_img	all_img;
	t_fct		fcts;
	t_settings	settings;
	long		last_frame;
	long		delay;
}	t_game;

#endif
