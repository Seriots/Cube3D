/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STRUCT_BONUS_H
# define C3D_STRUCT_BONUS_H
# include <X11/X.h>
# include <stdbool.h>

# include "dict.h"

# include "c3d_settings.h"

# ifndef HIDE
#  define HIDE 0
# endif

typedef struct s_game	t_game;

typedef struct s_objinit
{
	char	*tag;
	int		(*fct)(t_game *, char *, char *);
}	t_objinit;

typedef struct s_savset
{
	char	*tag;
	void	*ptr;
	int		(*fct)(void *, char *);
}	t_savset;

typedef struct	s_save
{
	char	*key;
	void	*value;
}	t_save;


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
	t_img_data	key_icon;
	t_img_data	flashlight[3];
}	t_all_img;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_angle
{
	double	value;
	double	cos;
	double	sin;
	double	tan;
}	t_angle;

typedef struct s_player
{
	t_coord	pos;
	t_angle	plane;
	double	updown;
	double	z;
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		turn_left;
	int		turn_right;
	int		turn_up;
	int		turn_down;
	int		crouch;
	int		run;
	double	speed;
}	t_player;

typedef struct s_wall
{
	double			dist;
	double			dist_from_start;
	char			face;
}				t_wall;

typedef struct s_settings
{
	float			fov;
	float			cam_sensibility_x;
	float			cam_sensibility_y;
	float			resolution;
	float			fps;
	float			scroll_speed;
	KeySym			run;
	KeySym			crouch;
	KeySym			left;
	KeySym			right;
	KeySym			forward;
	KeySym			backward;
	KeySym			turn_left;
	KeySym			turn_right;
	KeySym			turn_up;
	KeySym			turn_down;
	KeySym			pause;
	KeySym			interact;
	KeySym			drop;
	KeySym			slot1;
	KeySym			slot2;
	KeySym			slot3;
	KeySym			slot4;
	KeySym			slot5;
	KeySym			slot6;
	KeySym			slot7;
	KeySym			slot8;
	bool			color;
	bool			invert_scroll;
	bool			invert_mouse;
	bool			show_fps;
	bool			show_mmap;
	bool			show_seed;
	int				difficulty;
	char			*map_path;
	unsigned long	seed;
}	t_settings;

typedef struct s_object
{
	t_img_data	*all_img;
	t_img_data	*game_img;
	t_img_data	*hand_img;
	t_img_data	*menu_img;
	t_coord		pos;
	int			state;
	int			use_count;
	int			is_visible;	
	int			is_collide;
	int			start_frame;
	int			nb_image;
	int			animation_duration;
	int			(*interact)(t_game *game, t_dict *elem, struct s_object *obj);
	int			(*use)(t_game *game, t_dict *elem, struct s_object *obj);
	int			(*drop)(t_game *game, t_dict *elem, struct s_object *obj);
	int			(*collide)(t_game *game, t_dict *elem, struct s_object *obj);
	int			(*update)(t_game *game, t_dict *elem, struct s_object *obj);
	int			(*delete)(t_game *game, t_dict *elem, struct s_object *obj);
}	t_object;

typedef struct s_init
{
	char	*tag;
	int		(*fct)(t_game *game, t_object **object);
}	t_init;

typedef struct s_map
{
	char		**map;
	int			height;
	int			width;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			f;
	int			c;
	t_dict		*all_objects;
	char		default_north[256];
	char		default_south[256];
	char		default_west[256];
	char		default_east[256];
	char		default_ceil[256];
	char		default_floor[256];
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_display
{
	double		min;
	double		max;
	double		d;
	double		angle;
	double		fc_dist[WIN_HEIGHT];
	t_img_data	*img;
	int			x;
	double		factor;
	int			bpp;
}	t_display;

typedef struct s_vector
{
	double	x;
	double	y;
	t_angle	angle;
}	t_vector;


/*x y are positive*/
typedef struct s_collide_box
{
	int		x;
	int		y;
	int		x_text;
	int		y_text;
	int		width;
	int		height;
	char	font[256];
	char	description[256];
	int		(*mouse_press)(int button, int x, int y, t_game *game);
	int		(*mouse_release)(int button, int x, int y, t_game *game);
}	t_collide_box;

typedef struct s_button
{
	t_collide_box	box;
}	t_button;

typedef struct s_slidebar
{
	t_collide_box	box;
	int				min;
	int				max;
	int				x;
	int				y;
	int				width;
	int				height;
	float			*modified_value;
}	t_slidebar;

typedef struct s_multichoice
{
	t_collide_box	box;
	int				min;
	int				max;
	int				current;
	char			all_values[256][256];
	int				*modified_value;
}	t_multichoice;

typedef struct s_checkbox
{
	t_collide_box	box;
	bool			is_check;
	bool			*modified_value;
}	t_checkbox;

typedef struct s_keyinput
{
	t_collide_box	box;
	unsigned int	color;
	bool			is_selected;
	KeySym			*modified_value;
}	t_keyinput;

typedef struct s_textinput
{
	t_collide_box	box;
	int				shift;
	int				caps_lock;
	bool			is_selected;
	int				size;
	int				max_size;
	t_img_data		*modified_value;
	char			**modified_path;
	int				max_char_display;
	int				start_display;
	char			path[256];
}	t_textinput;

typedef struct s_mapinput
{
	t_collide_box	box;
	int				shift;
	int				caps_lock;
	bool			is_selected;
	int				size;
	int				max_size;
	t_img_data		*modified_value;
	char			**modified_path;
	int				max_char_display;
	int				start_display;
	char			path[256];
	char			*map_path;
	int				use_map_path;
}	t_mapinput;

typedef struct s_numbox
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	value;
}	t_numbox;

typedef struct s_numtinput
{
	t_collide_box	box;
	int				is_selected;
	int				red;
	int				green;
	int				blue;
	int				*modified_value;
	int				press_case;
}	t_numinput;

typedef struct s_seed
{
	t_collide_box	box;
	int				is_selected;
	unsigned long	tmp_value;
	unsigned long	*modified_value;
}	t_seed;

typedef struct s_scrollbar
{
	t_collide_box	box;
	int				min;
	int				max;
	int				max_obj;
	int				click_position;
	int				is_selected;
	int				*modified_value;
}	t_scrollbar;

/*for all type of object, box need to be the first elem*/
typedef struct s_menu
{
	t_dict	*all_objects;
	int		error;
	int		scroll_amount;
}	t_menu;

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
	int	(*mousepressed_fct)(int button, int x, int y, t_game *game);
	int	(*mousereleased_fct)(int button, int x, int y, t_game *game);
	int	(*mousemove_fct)(int x, int y, t_game *game);
}	t_fct;

typedef struct s_inventory
{
	t_object	*items[8];
	int			size;
	int			selected;
}	t_inventory;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_inventory	inventory;
	t_all_img	all_img;
	t_fct		fcts;
	t_settings	settings;
	t_menu		menu;
	t_menu		start_menu;
	t_display	display;
	int			pick_obj;
	long		last_frame;
	long		delay;
}	t_game;

#endif