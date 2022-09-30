/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:12:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 15:05:26 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_MENU_H
# define C3D_MENU_H

# include "c3d_struct.h"

typedef struct s_collide_box
{
	int	x;
	int	y;
	int	width;
	int	height;
}	t_collide_box;

typedef struct s_checkbox
{
	t_collide_box	collide_box;
	int				(*mouspressed_fct)(int button, int x, int y, t_game *game);
	int				(*mousreleased_fct)(int button, int x, int y, t_game *game);
}	t_checkbox;

/*Display*/
int	menu_display(t_game *game);

/*Update*/
int	menu_update(t_game *game);

int	open_menu(t_game *game);
int	close_menu(t_game *game);	
int	menu_mouse_move(int x, int y, t_game *game);
int	menu_mouse_release(int button, int x, int y, t_game *game);
int	menu_mouse_press(int button, int x, int y, t_game *game);
int	menu_key_release(KeySym keycode, t_game *game);
int	menu_key_press(KeySym keycode, t_game *game);

#endif
