/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:09:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:09:31 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_EVENT_H
# define C3D_EVENT_H

# include "c3d_struct.h"

/*Menu Event*/
int	checkbox_press(int button, int x, int y, t_game *game);
int	keyinput_press(int button, int x, int y, t_game *game);
int	numinput_press(int button, int x, int y, t_game *game);
int	slidebar_press(int button, int x, int y, t_game *game);
int	textinput_press(int button, int x, int y, t_game *game);
int	mapinput_press(int button, int x, int y, t_game *game);
int	multichoice_press(int button, int x, int y, t_game *game);
int	seed_press(int button, int x, int y, t_game *game);

/*Check Value*/
int	check_value_checkbox(bool *value);
int	check_value_keyinput(KeySym *value, int default_value);
int	check_value_slidebar(float *value, int min, int max);

/*Default events*/
int	default_key_release(KeySym keycode, t_game *game);
int	default_key_press(KeySym keycode, t_game *game);
int	default_mouse_press(int button, int x, int y, t_game *game);
int	default_mouse_release(int button, int x, int y, t_game *game);
int	default_mouse_move(int x, int y, t_game *game);

/*Hooks*/
int	event_key_press(KeySym keycode, t_game *game);
int	event_key_release(KeySym keycode, t_game *game);
int	event_mouse_move(int x, int y, t_game *game);
int	event_mouse_press(int button, int x, int y, t_game *game);
int	event_mouse_release(int button, int x, int y, t_game *game);
int	close_window(t_game *game);

/*Button exit*/
int	exit_event(int button, int x, int y, t_game *game);

/*Button resume*/
int	resume_event(int button, int x, int y, t_game *game);

/*Utils*/
int	press_collide_cond(t_game *game, int x, int y, t_dict *tmp);
int	press_scrollbar_cond(t_game *game, int x, int y, t_dict *tmp);

/*Action*/
int	objects_interact(t_game *game);
int	objects_drop(t_game *game);
int	objects_use(t_game *game);

#endif