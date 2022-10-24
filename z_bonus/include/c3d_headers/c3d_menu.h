/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:12:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 16:01:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MENU_H
# define C3D_MENU_H

# include "c3d_struct.h"

# include "dict.h"

/*Loop*/
int		init_settings_menu2(t_game *game);
int		init_settings_menu(t_game *game);
int		init_start_menu(t_game *game);
int		init_score_menu(t_game *game);
int		init_end_menu(t_game *game);

/*Display*/
int		display_slidebar_text(t_game *game, t_slidebar *slidebar);
int		display_button_text(t_game *game, t_button *button);
int		display_keyinput_text(t_game *game, t_keyinput *keyinput);
int		display_textinput_text(t_game *game, t_textinput *textinput);
int		display_checkbox_text(t_game *game, t_checkbox *checkbox);
int		display_numinput_text(t_game *game, t_numinput *numinput);
int		display_multichoice_text(t_game *game, t_multichoice *multichoice);
int		menu_display(t_game *game);

/*Update*/
int		draw_slidebar(t_game *game, void *slidebar);
int		draw_button(t_game *game, void *box);
int		draw_checkbox(t_game *game, void *checkbox);
int		draw_keyinput(t_game *game, void *box);
int		draw_textinput(t_game *game, void *box);
int		draw_numinput(t_game *game, void *box);
int		draw_multichoice(t_game *game, void *box);
int		draw_scrollbar(t_game *game, void *box);
int		menu_update(t_game *game);

/*Event*/
int		open_menu(t_game *game);
int		close_menu(t_game *game);	
int		menu_mouse_move(int x, int y, t_game *game);
int		menu_mouse_release(int button, int x, int y, t_game *game);
int		menu_mouse_press(int button, int x, int y, t_game *game);
int		menu_key_release(KeySym keycode, t_game *game);
int		menu_key_press(KeySym keycode, t_game *game);
int		check_all_objects_press(t_game *game, int x, int y, t_dict *dict);
int		check_all_objects_release(t_game *game, int x, int y, t_dict *dict);

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
t_dict	*init_textinput_floor(t_game *game);
t_dict	*init_textinput_ceil(t_game *game);
t_dict	*init_numinput_ceil(t_game *game);
t_dict	*init_scrollspeed_slidebar(t_game *game);
t_dict	*init_invertscroll_checkbox(t_game *game);
t_dict	*init_camspeedx_slidebar(t_game *game);
t_dict	*init_camspeedy_slidebar(t_game *game);
t_dict	*init_showfps_checkbox(t_game *game);
t_dict	*init_invertmouse_checkbox(t_game *game);
t_dict	*init_resolution_slidebar(t_game *game);
t_dict	*init_fps_slidebar(t_game *game);
t_dict	*init_showmmap_checkbox(t_game *game);
t_dict	*init_showseed_checkbox(t_game *game);
t_dict	*init_drop_keyinput(t_game *game);
t_dict	*init_interact_keyinput(t_game *game);
t_dict	*init_run_keyinput(t_game *game);
t_dict	*init_crouch_keyinput(t_game *game);
t_dict	*init_slot1_keyinput(t_game *game);
t_dict	*init_slot2_keyinput(t_game *game);
t_dict	*init_slot3_keyinput(t_game *game);
t_dict	*init_slot4_keyinput(t_game *game);
t_dict	*init_slot5_keyinput(t_game *game);
t_dict	*init_slot6_keyinput(t_game *game);
t_dict	*init_slot7_keyinput(t_game *game);
t_dict	*init_slot8_keyinput(t_game *game);

/*Utils*/
int		clear_all_other_selected(t_game *game, void *keyinput, t_dict *dict);
int		get_key_col(t_game *game, t_menu *menu, KeySym *key);
int		update_key_color(t_game *game, t_menu *menu);
int		edit_rgb(t_numinput *numinput);
int		get_number_from_key(KeySym key);
int		add_number(t_numinput *numinput, int n);
int		delete_number(t_numinput *numinput);
int		get_case_clicked(t_game *game, t_numinput *numinput, int x, int y);
int		reset_key_event(t_game *game);
int		reset_key_event_num(t_game *game, t_numinput *numinput);
char	get_char_from_key(KeySym key, int shift, int caps);
void	load_path(t_game *game, t_textinput *textinput, char **path);
void	init_textinput(t_textinput *textinput);
void	reset_textinput(t_game *game, t_textinput *textinput);
void	reset_textinput_start(t_game *game, t_textinput *textinput);
void	reset_seed(t_seed *seed);
int		event_enter_textinput(t_game *game, t_textinput *textinput);
int		event_enter_textinput_start(t_game *game, t_textinput *textinput);
int		release_cond_textinput(t_game *game,
			t_textinput *textinput, int x, int y);
int		release_cond_textinput_start(t_game *game,
			t_textinput *textinput, int x, int y);
int		scroll_up(t_game *game, t_menu *menu, char *tag);
int		scroll_down(t_game *game, t_menu *menu, char *tag);
int		add_number_seed(t_seed *seed, int keyint);
int		set_map_settings(t_game *game, t_dict **menu);
int		check_one_obj_press(t_game *game, int x, int y, t_dict *tmp);
int		check_one_obj_press_end(t_game *game, int x, int y, t_dict *tmp);
int		validate_seed(t_game *game, t_seed *seed);

/*End Menu*/
int		end_key_release(KeySym keycode, t_game *game);
int		end_key_press(KeySym keycode, t_game *game);
int		end_mouse_press(int button, int x, int y, t_game *game);
int		end_mouse_release(int button, int x, int y, t_game *game);
int		end_mouse_move(int x, int y, t_game *game);
int		endmenu_update(t_game *game);
int		endmenu_display(t_game *game);

t_dict	*init_retry_button(t_game *game);
t_dict	*init_mainmenu_button(t_game *game);
t_dict	*init_scrollbar_end(t_game *game);
t_dict	*init_nameinput_end(t_game *game);

int		draw_nameinput(t_game *game, void *box);
int		display_nameinput_text(t_game *game, t_nameinput *textinput);
int		draw_button_end(t_game *game, void *box);
int		display_button_text_end(t_game *game, t_button *button);
int		draw_scrollbar_end(t_game *game, void *box);
int		nameinput_press(int button, int x, int y, t_game *game);
void	init_nameinput(t_game *game, t_nameinput *nameinput);
int		release_cond_nameinput(t_game *game, t_nameinput *textinput,
			int x, int y);

/*Score Menu*/
int		check_all_objects_press_start(t_game *game, int x, int y, t_dict *dict);
int		check_all_objects_release_start(t_game *game, int x, int y,
			t_dict *dict);
int		draw_scrollbar_score(t_game *game, void *box);

int		multichoice_press_score(int button, int x, int y, t_game *game);
int		set_height_score(t_game *game, int *max_obj, int size);
int		set_height_s(t_game *game, t_scrollbar *scrollbar, t_score *score);

int		scorescreen_key_press(KeySym keycode, t_game *game);
int		scorescreen_key_release(KeySym keycode, t_game *game);
int		scorescreen_mouse_press(int button, int x, int y, t_game *game);
int		scorescreen_mouse_release(int button, int x, int y, t_game *game);
int		scorescreen_mouse_move(int x, int y, t_game *game);

int		score_update(t_game *game);
int		score_display(t_game *game);

t_dict	*init_return_button(t_game *game);
t_dict	*init_multichoice_difficulty_score(t_game *game);
t_dict	*init_scrollbar_score(t_game *game);
#endif
