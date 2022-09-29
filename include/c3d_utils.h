/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:51:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 17:48:07 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_UTILS_H
# define C3D_UTILS_H

# include "c3d_struct.h"

/*Math*/
double	min(double a, double b);
int		sign(float x);
int		pure_sign(float x);
double	dabs(double nbr);

/*Time*/
long	timestamp_msec(long start);
long	timestamp_sec(long start);

/*Error*/
int		display_error(int code);

/*Free*/
void	free_img_array(t_game *game, t_img_data **imgs_ptr, int number);
void	free_map(t_map *map);
void	free_game(t_game *game);

#endif
