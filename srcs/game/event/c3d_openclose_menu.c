/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_openclose_menu.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:55:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 15:06:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "mlx.h"

int	open_menu(t_game *game)
{
	game->fcts.display_fct = menu_display;
	game->fcts.update_fct = menu_update;
	game->fcts.keyreleased_fct = menu_key_release;
	game->fcts.keypressed_fct = menu_key_press;
	game->fcts.mousemove_fct = menu_mouse_move;
	game->fcts.mousepressed_fct = menu_mouse_press;
	game->fcts.mousereleased_fct = menu_mouse_release;
	mlx_mouse_show(game->mlx.display, game->mlx.window);
	return (0);
}

int	close_menu(t_game *game)
{
	game->fcts.display_fct = default_display;
	game->fcts.update_fct = default_update;
	game->fcts.keyreleased_fct = default_key_release;
	game->fcts.keypressed_fct = default_key_press;
	game->fcts.mousemove_fct = default_mouse_move;
	game->fcts.mousepressed_fct = default_mouse_press;
	game->fcts.mousereleased_fct = default_mouse_release;
	mlx_mouse_hide(game->mlx.display, game->mlx.window);
	return (0);
}
