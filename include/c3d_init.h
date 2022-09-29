/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:14:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 10:53:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_INIT_H
# define C3D_INIT_H

# include "c3d_struct.h"

/*Init images*/
int	init_xpm_image(t_game *game, t_img_data *img, char *name);
int	init_image(t_game *game, int width, int height, t_img_data *img);

/*Textures*/
int	open_textures(t_game *game, t_map *map);

/*Image*/
int	init_images(t_game *game);

/*Player*/
int	init_player(t_game *game);

/*Game*/
int	init_game(t_game *game, int first);

/*Mlx*/
int	init_mlx(t_game *game);

/*Start*/
int	start_game(t_game *game);

#endif
