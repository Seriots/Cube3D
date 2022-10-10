/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:51:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:08:57 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_UTILS_BONUS_H
# define C3D_UTILS_BONUS_H

# include "c3d_struct.h"

/*Color*/
unsigned int	get_color(t_game *game, unsigned int color);

/*Math*/
int				abs(int x);
double			max(double a, double b);
double			min(double a, double b);
int				sign(float x);
int				pure_sign(float x);
double			dabs(double nbr);
double			norm(double x, double y);

/*Time*/		
long			timestamp_msec(long start);
long			timestamp_sec(long start);

/*Error*/
void			set_error_value(t_menu *menu, int code);
char			*get_error(int code);
void			display_error_on_screen(t_game *game, char *error, int x, int y);
int				display_error(int code);

/*Free*/
void			free_textures(t_game *game, t_all_img *all_img);
void			free_img_array(t_game *game, t_img_data **imgs_ptr, int number);
void			free_map(t_map *map);
void			free_game(t_game *game);

#endif
