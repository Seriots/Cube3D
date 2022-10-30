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

#ifndef C3D_UTILS_H
# define C3D_UTILS_H

# include "c3d_struct.h"

/*Object*/
int				is_player_facing(t_game *game, t_object *obj, double marge);
double			get_angle_player_obj(t_game *game, t_object *obj, double marge);

/*Game Error*/
int				set_error_message(t_game *game, char *message, int duration);

/*Inventory*/
int				move_slot(KeySym keycode, t_game *game);
int				add_items(t_game *game, t_inventory *inventory,
					t_object *object);
int				drop_items(t_game *game, t_inventory *inventory,
					t_object *object);

/*Save*/
int				sf(void *ptr, char *value);
int				si(void *ptr, char *value);
int				ss(void *ptr, char *value);
int				ssn(void *ptr, char *value);

/*Color*/
unsigned int	get_color(int color_settings, unsigned int color);

/*Display*/
int				set_screen_data(t_screen_data *pixel, double dist, int color);

/*Doors*/
t_object		*find_door(t_game *game, int i, int j);

/*Math*/
int				is_in_circle(int x, int y, unsigned int color);
int				abs(int x);
double			max(double a, double b);
double			min(double a, double b);
int				sign(float x);
int				pure_sign(float x);
double			dabs(double nbr);
double			norm(double x, double y);
double			ft_floor(double nbr);
double			ft_ceil(double nbr);
double			dist_to_obj(t_coord player, t_coord obj);
double			get_obj_angle(double x, double y);
int				cmp_obj_dist(t_dict *dict1, t_dict *dict2);

/*Time*/		
long			timestamp_msec(long start);
long			timestamp_sec(long start);

/*Error*/
void			set_error_value(t_menu *menu, int code);
char			*get_error(int code);
void			display_error_on_screen(t_game *game, char *err, int x, int y);
int				display_error(int code);

/*Free*/
int				free_doors(t_game *game);
void			free_lightmask(double **array);
void			dict_clear_with_inventory(t_game *game, t_dict **dict);
void			free_map_with_inventory(t_game *game, t_map *map);
void			free_textures(t_game *game, t_all_img *all_img);
void			free_img_array(t_game *game, t_img_data **imgs_ptr, int number);
void			free_images(t_game *game);
void			free_images2(t_game *game);
void			free_images3(t_game *game);
void			free_map(t_game *game, t_map *map);
void			free_game(t_game *game);

#endif
