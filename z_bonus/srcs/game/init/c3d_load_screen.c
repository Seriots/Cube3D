/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_load_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:30:36 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 10:30:44 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_startscreen.h"
#include "c3d_event.h"
#include "c3d_menu.h"
#include "c3d_loop.h"

#include "mlx.h"

int	load_startscreen(t_game *game)
{
	game->fcts.update_fct = startscreen_update;
	game->fcts.display_fct = startscreen_display;
	game->fcts.keypressed_fct = startscreen_key_press;
	game->fcts.keyreleased_fct = startscreen_key_release;
	game->fcts.mousepressed_fct = startscreen_mouse_press;
	game->fcts.mousereleased_fct = startscreen_mouse_release;
	game->fcts.mousemove_fct = startscreen_mouse_move;
	game->menu.scroll_amount = 0;
	if (HIDE)
		mlx_mouse_show(game->mlx.display, game->mlx.window);
	mlx_do_key_autorepeaton(game->mlx.display);
	return (0);
}

int	load_menu(t_game *game)
{
	game->fcts.display_fct = menu_display;
	game->fcts.update_fct = menu_update;
	game->fcts.keyreleased_fct = menu_key_release;
	game->fcts.keypressed_fct = menu_key_press;
	game->fcts.mousemove_fct = menu_mouse_move;
	game->fcts.mousepressed_fct = menu_mouse_press;
	game->fcts.mousereleased_fct = menu_mouse_release;
	if (HIDE)
		mlx_mouse_show(game->mlx.display, game->mlx.window);
	mlx_do_key_autorepeaton(game->mlx.display);
	return (0);
}

int	load_default(t_game *game)
{
	game->fcts.display_fct = default_display;
	game->fcts.update_fct = default_update;
	game->fcts.keyreleased_fct = default_key_release;
	game->fcts.keypressed_fct = default_key_press;
	game->fcts.mousemove_fct = default_mouse_move;
	game->fcts.mousepressed_fct = default_mouse_press;
	game->fcts.mousereleased_fct = default_mouse_release;
	if (HIDE)
		mlx_mouse_hide(game->mlx.display, game->mlx.window);
	mlx_do_key_autorepeatoff(game->mlx.display);
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
