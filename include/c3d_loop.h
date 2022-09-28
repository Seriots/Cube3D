/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:19:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 10:42:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOOP_H
# define C3D_LOOP_H

#include "c3d_struct.h"

/*Ray Casting*/
int		raycasting(t_game *game);

/*Display*/
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int 	default_display(t_game *game);

/*Minimap update*/
int		update_minimap(t_game *game);

/*Player update*/
int		update_player(t_game *game);

/*Update*/
int 	default_update(t_game *game);

/*Loop*/
int		game_loop(t_game *game);

#endif