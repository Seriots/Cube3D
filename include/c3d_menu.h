/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:12:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 17:26:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MENU_H
# define C3D_MENU_H

# include "c3d_struct.h"

# include "dict.h"

/*Display*/
int	display_slidebar_text(t_game *game, t_slidebar *slidebar);
int	display_button_text(t_game *game, t_button *button);
int	display_keyinput_text(t_game *game, t_keyinput *keyinput);
int	display_textinput_text(t_game *game, t_textinput *textinput);
int	display_checkbox_text(t_game *game, t_checkbox *checkbox);
int	menu_display(t_game *game);

/*Update*/
int	draw_slidebar(t_game *game, t_slidebar *slidebar);
int	draw_button(t_game *game, t_button *box);
int	draw_checkbox(t_game *game, t_checkbox *checkbox);
int	draw_keyinput(t_game *game, t_keyinput *box);
int	draw_textinput(t_game *game, t_textinput *box);
int	menu_update(t_game *game);

/*Event*/
int	open_menu(t_game *game);
int	close_menu(t_game *game);	
int	menu_mouse_move(int x, int y, t_game *game);
int	menu_mouse_release(int button, int x, int y, t_game *game);
int	menu_mouse_press(int button, int x, int y, t_game *game);
int	menu_key_release(KeySym keycode, t_game *game);
int	menu_key_press(KeySym keycode, t_game *game);

/*Init*/
t_dict	*init_exit_button(t_game *game);
t_dict	*init_resume_button(t_game *game);
t_dict	*init_fov_slidebar(t_game *game);
t_dict	*init_color_checkbox(t_game *game);
t_dict	*init_forward_keyinput(t_game *game);
t_dict	*init_left_keyinput(t_game *game);
t_dict	*init_textinput_north(t_game *game);

/*Utils*/
int	clear_all_other_selected(t_game *game, void *keyinput);
int	get_key_color(t_game *game, KeySym *key);
int	update_key_color(t_game *game, t_menu *menu);

#endif
