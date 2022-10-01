/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:59:33 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/01 17:21:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_event.h"
#include "c3d_menu.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

int	menu_key_press(KeySym keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

int	menu_key_release(KeySym keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_menu(game);
	return (0);
}
