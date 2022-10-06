/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:19:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOOP_BONUS_H
# define C3D_LOOP_BONUS_H

# include "c3d_struct_bonus.h"

/*Ray Casting*/
int		intersect_wall(t_game *game, t_vector ray, t_wall *wall);
int		display_wall(t_game *game, t_wall *wall, int i);
int		raycasting(t_game *game);

/*Display*/
int		show_fps(t_game *game);
void	my_mlx_put_image_to_window(t_game *game, t_img_data *data, int x, int y);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		default_display(t_game *game);

/*Minimap update*/
int		update_minimap(t_game *game);

/*Player update*/
int		check_collide(t_game *game, t_point mov);
int		update_player(t_game *game);

/*Update*/
int		check_collide(t_game *game, t_point mov);
int		default_update(t_game *game);

/*Loop*/
int		game_loop(t_game *game);

#endif