/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:12:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 16:01:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MENU_BONUS_H
# define C3D_MENU_BONUS_H

# include "c3d_struct_bonus.h"

# include "dict.h"

/*Display*/
int	display_slidebar_text(t_game *game, t_slidebar *slidebar);
int	display_button_text(t_game *game, t_button *button);
int	display_keyinput_text(t_game *game, t_keyinput *keyinput);
int	display_textinput_text(t_game *game, t_textinput *textinput);
int	display_checkbox_text(t_game *game, t_checkbox *checkbox);
int	display_numinput_text(t_game *game, t_numinput *numinput);
int	menu_display(t_game *game);

/*Update*/
int	draw_slidebar(t_game *game, t_slidebar *slidebar);
int	draw_button(t_game *game, t_button *box);
int	draw_checkbox(t_game *game, t_checkbox *checkbox);
int	draw_keyinput(t_game *game, t_keyinput *box);
int	draw_textinput(t_game *game, t_textinput *box);
int	draw_numinput(t_game *game, t_numinput *box);
int	draw_scrollbar(t_game *game, t_scrollbar *box);
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
t_dict	*init_numinput_floor(t_game *game);
t_dict	*init_scrollbar(t_game *game);
t_dict	*init_backward_keyinput(t_game *game);
t_dict	*init_right_keyinput(t_game *game);
t_dict	*init_textinput_south(t_game *game);
t_dict	*init_textinput_east(t_game *game);
t_dict	*init_textinput_west(t_game *game);
t_dict	*init_numinput_ceil(t_game *game);
t_dict	*init_scrollspeed_slidebar(t_game *game);
t_dict	*init_invertscroll_checkbox(t_game *game);
t_dict	*init_camspeedx_slidebar(t_game *game);
t_dict	*init_camspeedy_slidebar(t_game *game);
t_dict	*init_showfps_checkbox(t_game *game);
t_dict	*init_invertmouse_checkbox(t_game *game);
t_dict	*init_resolution_slidebar(t_game *game);
t_dict	*init_fps_slidebar(t_game *game);

/*Utils*/
int	clear_all_other_selected(t_game *game, void *keyinput);
int	get_key_color(t_game *game, KeySym *key);
int	update_key_color(t_game *game, t_menu *menu);
int	edit_rgb(t_numinput *numinput);
int	get_number_from_key(KeySym key);
int	add_number(t_numinput *numinput, int n);
int	delete_number(t_numinput *numinput);
int	get_case_clicked(t_game *game, t_numinput *numinput, int x, int y);
int	reset_key_event(t_game *game);
int	reset_key_event_num(t_game *game, t_numinput *numinput);
char	get_char_from_key(KeySym key, int shift, int caps);
void	load_path(t_game *game, t_textinput *textinput, char **path);
void	init_textinput(t_textinput *textinput);
void	reset_textinput(t_game *game, t_textinput *textinput);
int		event_enter_textinput(t_game *game, t_textinput *textinput);
int		release_cond_textinput(t_game *game,
		t_textinput *textinput, int x, int y);
int	scroll_up(t_game *game);
int	scroll_down(t_game *game);

#endif
