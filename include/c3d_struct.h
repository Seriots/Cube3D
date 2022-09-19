/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:25:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 11:17:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STRUCT_H
# define C3D_STRUCT_H

typedef struct s_map
{
	char	**map;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F;
	int		C;
}	t_map;

typedef struct s_game
{
	t_map	map;
}	t_game;

#endif
