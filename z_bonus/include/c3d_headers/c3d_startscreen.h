/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:56:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 15:58:16 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_STARTSCREEN_H
# define C3D_STARTSCREEN_H

#include "c3d_struct.h"

/*Event*/
int	startscreen_display(t_game *game);
int	startscreen_update(t_game *game);

int	startscreen_mouse_move(int x, int y, t_game *game);
int	startscreen_mouse_release(int button, int x, int y, t_game *game);
int	startscreen_mouse_press(int button, int x, int y, t_game *game);
int	startscreen_key_release(KeySym keycode, t_game *game);
int	startscreen_key_press(KeySym keycode, t_game *game);

/*Update*/
int	draw_button_start(t_game *game, t_button *box);
int	draw_seed(t_game *game, t_seed *box);

/*Display*/
int	display_seed_text(t_game *game, t_seed *seed);
int	display_button_text_start(t_game *game, t_button *button);

/*Init*/
t_dict	*init_play_button(t_game *game);
t_dict	*init_quit_button(t_game *game);
t_dict	*init_multichoice_difficulty(t_game *game);
t_dict	*init_seed(t_game *game);
#endif
