/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/20 14:48:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STRUCT_H
# define C3D_STRUCT_H

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
}	t_map;

typedef struct	s_player
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
