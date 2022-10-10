/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_settings.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:26:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 16:02:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_SETTINGS_BONUS_H
# define C3D_SETTINGS_BONUS_H

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
# define BUTTON2 "BUTTON2"
# define SLIDEBAR "SLIDEBAR"
# define CHECKBOX "CHECKBOX"
# define KEYINPUT "KEYINPUT"
# define TEXTINPUT "TEXTINPUT"
# define TEXTINPUT2 "TEXTINPUT2"
# define NUMINPUT "NUMINPUT"
# define SCROLLBAR "SCROLLBAR"
# define MULTICHOICE "MULTICHOICE"
# define SEED "SEED"

# define MARGE 40
/*BETWEEN 1-20*/
# define SCROLL_SPEED 8.0

# define KEYINPUT_START_X 125
# define KEYINPUT_START_Y 50

# define TEXTINPUT_START_X 125
# define TEXTINPUT_START_Y 225

# define NUMINPUT_START_X 125
# define NUMINPUT_START_Y 400

/*MENU_WIDTH - 275*/
# define SLIDEBAR_START_X 525
# define SLIDEBAR_START_Y 50

/*MENU_WIDTH - 275*/
# define CHECKBOX_START_X 525
# define CHECKBOX_START_Y 305

# define FONT "-sony-*-*-*-*-*-*-400-*-*-*-*-iso8859-*"

/*WIN WIDTH / 2*/
# define START_MENU_ERROR_X 640 
# define START_MENU_ERROR_Y 150

/*WIN WIDTH / 2*/
# define MENU_ERROR_X 640
# define MENU_ERROR_Y 585

/*MiniMap Settings*/
# define MMAP_WIDTH 200
# define MMAP_HEIGHT 200
# define MMAP_CASE_SIZE 10

# define IMAGE_EXTENSION ".xpm"
# define NAME_BUFFER_SIZE 251
# define NUMBER_BUFFER_SIZE 11

# define MAX_LONG 9223372036854775807

# define CASE_SIZE 64

/*Default Settings*/

/*Mouse sensibility between 1-100*/
# define CAM_SENSIBILITY_X 30.0f
# define CAM_SENSIBILITY_Y 30.0f

/*Field of view between 1-60*/
# define FOV 10.0f
# define FPS 60
# define VIEW_SIZE 9
# define VIEW_SCREEN 16
# define RESOLUTION 100 // 1 - 100

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
