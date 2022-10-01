/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:09:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 12:02:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_EVENT_H
# define C3D_EVENT_H

# include "c3d_struct.h"

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

#endif