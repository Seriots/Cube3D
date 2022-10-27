/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:14:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:23 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_INIT_H
# define C3D_INIT_H

# include "c3d_struct.h"

/*Add score*/
int		sort_scores(t_score *score);
int		save_scores(t_game *game, t_score *score, char *file);
char	*get_score_file(t_game *game);
t_score	*get_score_array(t_game *game);
int		print_scores(t_score *score);
int		add_scores(t_game *game, t_score *score, char *key, int value);
int		init_scores(t_game *game, t_score *score, char *file);

/*Save*/
int		load_settings(t_game *game);
int		save_settings(t_game *game);

/*Load*/
int		load_scorescreen(t_game *game);
int		load_endscreen(t_game *game);
int		load_startscreen(t_game *game);
int		load_default(t_game *game);
int		load_menu(t_game *game);
int		load_gameover(t_game *game);

/*Init images*/
int		init_images_group(t_game *game, char *path,
			int nb_of_images, t_img_data **dst_ptr);
int		init_xpm_image(t_game *game, t_img_data *img, char *name);
int		init_image(t_game *game, int width, int height, t_img_data *img);

/*Menu*/
int		init_menu(t_game *game);

/*Textures*/
int		open_textures(t_game *game, t_map *map);
int		open_start_textures(t_game *game);

/*Image*/
int		init_images(t_game *game);

/*Player*/
int		init_lightmask(t_game *game);
int		init_player(t_game *game, t_map *map, t_player *player, int first);

/*Game*/
int		init_game(t_game *game, char *path);

/*Start map*/
int		init_all_map_parameters(t_game *game, int first);
int		get_all_doors(t_game *game, t_map *map);
int		init_start_map(t_game *game);

/*Mlx*/
int		init_mlx(t_game *game);

/*Start*/
int		start_game(t_game *game, char **argv, int argc);

#endif
