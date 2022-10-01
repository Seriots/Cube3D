/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:12:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 21:05:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MENU_H
# define C3D_MENU_H

# include "c3d_struct.h"

# include "dict.h"

/*Display*/
int	menu_display(t_game *game);

/*Update*/
int	draw_slidebar(t_game *game, t_slidebar *slidebar);
int	draw_button(t_game *game, t_button *box);
int	menu_update(t_game *game);

int	open_menu(t_game *game);
int	close_menu(t_game *game);	
int	menu_mouse_move(int x, int y, t_game *game);
int	menu_mouse_release(int button, int x, int y, t_game *game);
int	menu_mouse_press(int button, int x, int y, t_game *game);
int	menu_key_release(KeySym keycode, t_game *game);
int	menu_key_press(KeySym keycode, t_game *game);

t_dict	*init_exit_button(t_game *game);
t_dict	*init_resume_button(t_game *game);
t_dict	*init_fov_slidebar(t_game *game);


#endif
