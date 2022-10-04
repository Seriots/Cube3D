/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:26:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 17:58:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SETTINGS_H
# define C3D_SETTINGS_H

# include <X11/keysym.h>
# include <math.h>

/*Window Settings*/
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define WIN_TITLE "Cub3D"

/*Menu Settings*/
# define MENU_WIDTH 800
# define MENU_HEIGHT 600
# define BORDER_SIZE 5

# define BUTTON "BUTTON"
# define SLIDEBAR "SLIDEBAR"
# define CHECKBOX "CHECKBOX"
# define KEYINPUT "KEYINPUT"
# define TEXTINPUT "TEXTINPUT"
# define NUMINPUT "NUMINPUT"
# define SCROLLBAR "SCROLLBAR"

/*MiniMap Settings*/
# define MMAP_WIDTH 200
# define MMAP_HEIGHT 200
# define MMAP_CASE_SIZE 10

# define IMAGE_EXTENSION ".xpm"
# define NAME_BUFFER_SIZE 251
# define NUMBER_BUFFER_SIZE 11

# define COLOR 0x00FF0000

# define MAX_LONG 9223372036854775807

# define CASE_SIZE 64

/*Default Settings*/

/*Mouse sensibility between 0-100*/
# define SENSIBILITY 0.0f

# define FPS 30
# define FOV 10.0f
# define VIEW_SIZE 9
# define VIEW_SCREEN 16
# define QUALITY 1 // 1 - 64

# define MOVE_SPEED 10.0f
# define TURN_SPEED 0.06f

/*Default Key*/
/*
# define DEFAULT_LEFT XK_a
# define DEFAULT_RIGHT XK_d
# define DEFAULT_FORWARD XK_w
# define DEFAULT_BACKWARD XK_s
# define DEFAULT_TURN_LEFT XK_Left
# define DEFAULT_TURN_RIGHT XK_Right
# define DEFAULT_PAUSE XK_Escape
*/
#endif
