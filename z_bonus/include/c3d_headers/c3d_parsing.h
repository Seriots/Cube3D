/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:28:15 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_PARSING_BONUS_H
# define C3D_PARSING_BONUS_H

# include "c3d_struct.h"

/*Square Map*/
int		set_square_map(t_map *map);

/*Check*/
int		check_map(t_map *map);

/*Set*/
void	set_map(t_map *map);
int		set_map_size(char *file, int *size);

/*Readfile*/
int		read_file(t_map *map, char *file, int size);

/*Utils*/
int		is_only_set(char *line, char *set);
int		ft_color(char *line);

int		parsing(t_map *map, char *file);

#endif
