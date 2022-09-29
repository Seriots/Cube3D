/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:19:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 18:46:33 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOOP_H
# define C3D_LOOP_H

# include "c3d_struct.h"

/*Ray Casting*/
int		intersect_wall(t_game *game, t_vector ray, t_wall *wall);
int		display_wall(t_game *game, t_wall *wall, int i);
int		raycasting(t_game *game);

/*Display*/
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		default_display(t_game *game);

/*Minimap update*/
int		update_minimap(t_game *game);

/*Player update*/
int		update_player(t_game *game);

/*Update*/
int		check_collide (t_game *game, int mov_x, int mov_y);
int		default_update(t_game *game);

/*Loop*/
int		game_loop(t_game *game);

#endif