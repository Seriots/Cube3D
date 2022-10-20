/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_end_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:48:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 20:48:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_event.h"
#include "c3d_menu.h"
#include "c3d_init.h"

#include "mlx.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

int	end_key_press(KeySym keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

int	end_key_release(KeySym keycode, t_game *game)
{
	if (keycode == XK_Escape)
		load_startscreen(game);
	return (0);
}