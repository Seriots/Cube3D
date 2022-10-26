/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:19:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_LOOP_H
# define C3D_LOOP_H

# include "c3d_struct.h"

/*Sound*/
int		play_sound(char *file);

/*NextStage*/
int		next_stage(t_game *game);
int		load_new_map(t_game *game, char *map_path);

/*Menuing*/
int		draw_all_objects(t_game *game, t_dict *dict);
int		display_text(t_game *game, t_dict *dict);

/*Ray Casting*/
int		intersect_wall(t_game *game, t_vector ray, t_wall *wall, int i);
int		display_wall(t_game *game, t_wall *wall, int i);
int		raycasting(t_game *game);

/*Display*/
int		display_lightbar(t_game *game, t_object *obj);
int		display_lifebar(t_game *game);
int		display_staminabar(t_game *game);
int		display_hand(t_game *game);
int		display_inventory(t_game *game);
int		show_fps(t_game *game);
int		show_seed(t_game *game);
void	my_mlx_put_image_to_window(t_game *game, t_img_data *data,
			int x, int y);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int		display_all_sprites(t_game *game);
int		default_display(t_game *game);

/*Minimap update*/
int		update_minimap(t_game *game);

/*Player update*/
int		check_collisions_objects(t_game *game, t_dict *all_objects);
int		check_collide(t_game *game, t_coord mov);
int		update_player(t_game *game);

/*Update*/
int		update_objects(t_game *game, t_dict *all_objects);
int		default_update(t_game *game);

/*Loop*/
int		game_loop(t_game *game);

#endif