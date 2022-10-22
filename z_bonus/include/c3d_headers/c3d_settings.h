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

/*Menu Settings*/
# define ENDMENU_WIDTH 500
# define ENDMENU_HEIGHT 600
# define END_BORDER_SIZE 5
# define END_ANIMATION_DURATION 1500.0
# define END_FADE_DURATION 1100.0
# define END_GAMEOVER_DURATION 1400.0
# define END_STAT_MARGE 30

/*Hot bar*/
# define HOTBAR_CASE_SIZE 60
# define HOTBAR_BIG_BORDER 2
# define HOTBAR_CASE_BORDER 2

/*Bar settings*/
# define BAR_WIDTH 300
# define BAR_HEIGHT 18

# define STAMINA_LOSS 0.04
# define STAMINA_GAIN 0.06
# define STAMINA_BASE_GAIN 0.004

# define LAMP_DECREASE 0.002
# define LAMP_INCREASE 0.00035

# define HAND_MOVEMENT_SPEED 0.15
# define HAND_CENTER_SPEED 0.09
# define HAND_MAX_X 20
# define HAND_MAX_Y 20

/*Transition settings*/
# define FADE_DURATION 750.0
# define LOADING_DURATION 3000.0

//HOTBAR_Y WIN_HEIGHT - HOTBAR_CASE_SIZE - 10
# define HOTBAR_Y 650

/*Font settings*/
# define FONT_WIDTH 6

# define BUTTON "BUTTON"
# define BUTTON2 "BUTTON2"
# define BUTTON3 "BUTTON3"
# define SLIDEBAR "SLIDEBAR"
# define CHECKBOX "CHECKBOX"
# define KEYINPUT "KEYINPUT"
# define TEXTINPUT "TEXTINPUT"
# define TEXTINPUT2 "TEXTINPUT2"
# define NAMEINPUT "NAMEINPUT"
# define NUMINPUT "NUMINPUT"
# define SCROLLBAR "SCROLLBAR"
# define SCROLLBAR2 "SCROLLBAR2"
# define MULTICHOICE "MULTICHOICE"
# define SEED "SEED"

# define MARGE 40
/*BETWEEN 1-20*/
# define SCROLL_SPEED 8.0

# define KEYINPUT_START_X 125
# define KEYINPUT_START_Y 50

# define TEXTINPUT_START_X 325
# define TEXTINPUT_START_Y 50

# define NUMINPUT_START_X 325
# define NUMINPUT_START_Y 225

/*MENU_WIDTH - 275*/
# define SLIDEBAR_START_X 325
# define SLIDEBAR_START_Y 350

/*MENU_WIDTH - 275*/
# define CHECKBOX_START_X 700
# define CHECKBOX_START_Y 50

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
# define VIEW_HEIGHT 9
# define VIEW_WIDTH 16
# define RESOLUTION 100 // 1 - 100

# define MOVE_SPEED 0.15
# define TURN_SPEED 0.06f

# define RUN_SPEED_FACTOR 1.8
# define CROUCH_SPEED_FACTOR 0.3

# define MIN_DIST_OBJ 48.0f
# define MIN_DIST_COLLIDE 20.0f

/*Save files*/
# define EASY_FILE "files/easy_scores.txt"
# define MEDIUM_FILE "files/medium_scores.txt"
# define HARD_FILE "files/hard_scores.txt"

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
