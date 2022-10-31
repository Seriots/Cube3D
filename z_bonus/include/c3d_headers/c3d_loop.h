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

/*NextStage*/
int				loading(t_game *game);
int				display_loading_message(t_game *game);
int				loading_display(t_game *game);
int				get_all_doors(t_game *game, t_map *map);
int				next_stage(t_game *game);
int				set_inventory(t_game *game);
int				load_new_map(t_game *game, char *map_path, int first);

/*Menuing*/
int				draw_all_objects(t_game *game, t_dict *dict);
int				display_text(t_game *game, t_dict *dict);
;
/*Start Raycasting*/
double			start_get_dist_obj(t_game *game, t_object *obj);
int				update_camera(t_game *game);
int				check_angle(double angle, double left_angle,
					double right_angle);
unsigned int	get_sprite_color(t_game *game, t_object *img,
					t_point p, int width);
int				start_display_all_sprites(t_game *game);
int				start_intersect_wall(t_game *game, t_vector ray, t_wall *wall);
int				start_display_wall(t_game *game, t_wall *wall, int i);
int				start_raycasting(t_game *game);

/*Ray Casting*/
int				display_wall_loop(t_game *game, t_wall *wall, t_point p);
unsigned int	damaged_ghost(t_object *obj, unsigned int color);
double			get_dist_obj(t_game *game, t_object *obj);
int				get_all_obj_dist(t_game *game);
unsigned int	get_door_color(t_game *game, t_img_data *img, int j);
int				draw_door_vline(t_game *game, t_img_data *img,
					int i, double dist);
int				display_door_vline(t_game *game, t_door *door, int i);
void			display_all_door(t_game *game, t_point *p, double dist);
int				shade_pixel_sprite(t_game *game, int color,
					double dist, t_point p);
int				shade_pixel(t_game *game, int i, int j);
unsigned int	get_wall_color(int pixel, t_display *display);
unsigned int	get_floor_color(t_game *game, int pixel,
					t_display *display, int start);
unsigned int	get_ceil_color(t_game *game, int pixel,
					t_display *display, int start);
int				is_lamp(t_game *game);
int				set_dist(double *dist_x, double *dist_y, t_vector pre_pos);
int				check_wall(t_game *game, t_map *map, t_vector vec,
					t_wall *wall);
t_vector		get_next_wall(t_vector pre_pos);
t_img_data		*get_image(t_all_img *all_img, char c);
int				get_pixel_color(t_game *game, t_wall *wall, t_point p,
					t_display *display);
int				intersect_wall(t_game *game, t_vector ray, t_wall *wall, int i);
int				display_wall(t_game *game, t_wall *wall, int i);
int				raycasting(t_game *game);

/*Display*/
int				display_level(t_game *game);
int				display_lightbar(t_game *game, t_object *obj);
int				display_lifebar(t_game *game);
int				display_staminabar(t_game *game);
int				display_hand(t_game *game);
int				display_inventory(t_game *game);
int				show_fps(t_game *game);
int				show_seed(t_game *game);
void			my_mlx_put_image_to_window(t_game *game, t_img_data *data,
					int x, int y);
void			my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int				display_all_sprites(t_game *game);
int				default_display(t_game *game);

/*Minimap update*/
int				update_minimap(t_game *game);

/*Player update*/
int				update_movement(t_game *game);
int				update_invicibe_frame(t_game *game);
int				check_collisions_objects(t_game *game, t_dict *all_objects);
int				check_collide(t_game *game, t_coord mov);
int				update_player(t_game *game);

/*Update*/
int				spawn_ennemies(t_game *game);
int				kill_ennemies(t_game *game);
int				update_objects(t_game *game, t_dict *all_objects);
int				default_update(t_game *game);

/*Loop*/
int				game_loop(t_game *game);

#endif