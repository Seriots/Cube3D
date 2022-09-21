/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/21 13:23:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STRUCT_H
# define C3D_STRUCT_H


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
	t_img_data	*no;
	t_img_data	*so;
	t_img_data	*we;
	t_img_data	*ea;
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

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	char			dir;
}	t_player;

typedef struct s_game
{
	t_map		map;
	t_player	player;
}	t_game;

#endif
