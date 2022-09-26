/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:22:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 13:02:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_event.h"

#include <X11/X.h>
#include <stdbool.h>
#include <X11/keysym.h>

#include <stdio.h>

int	default_key_press(int keycode, t_game *game)
{
	(void)game;
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	default_key_release(int keycode, t_game *game)
{
	(void)game;
	printf("Key released: %d\n", keycode);
	if (keycode == XK_Escape)
		close_window(game);
	return (0);
}

int	default_update(t_game *game)
{
	(void)game;
	return (0);
}

int	default_display(t_game *game)
{
	(void)game;
	return (0);
}
