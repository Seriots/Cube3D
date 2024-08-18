/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:59:11 by lgiband           #+#    #+#             */
/*   Updated: 2024/08/18 12:41:42 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SAVE_H
# define C3D_SAVE_H

# define VFOV "fov"
# define VCAM_X "x_sensibility"
# define VCAM_Y "y_sensibility"
# define VRES "resolution"
# define VFPS "fps"
# define VSCROLL_SPEED "scroll_speed"
# define VLEFT "key_left"
# define VRIGHT "key_right"
# define VFORWARD "key_forward"
# define VBACKWARD "key_backward"
# define VTURN_LEFT "key_turn_left"
# define VTURN_RIGHT "key_turn_right"
# define VPAUSE "key_pause"
# define VCOLOR "color"
# define VOSMODE "osmode"
# define VINVERT_SCROLL "invert_scroll"
# define VINVERT_MOUSE "invert_mouse"
# define VSHOWFPS "show_fps"
# define VSHOWMINIMAP "show_minimap"
# define VSHOWFLCE "showflce"
# define VSHOWSEED "show_seed"
# define VNO "north_image"
# define VSO "south_image"
# define VWE "west_image"
# define VEA "east_image"
# define VCEIL "ceil_color"
# define VFLOOR "floor_color"
# define VINTER	"interact"
# define VDROP "drop"
# define VRUN "run"
# define VCR "crouch"
# define V1 "slot1"
# define V2 "slot2"
# define V3 "slot3"
# define V4 "slot4"
# define V5 "slot5"
# define V6 "slot6"
# define V7 "slot7"
# define V8 "slot8"
# define VNAME "name"
# define VFL "floor_img"
# define VCE "ceil_img"

void	save_str(int fd, char *key, char *value);
void	save_int(int fd, char *key, int value);
void	save_color(int fd, char *key, int value);

#endif
