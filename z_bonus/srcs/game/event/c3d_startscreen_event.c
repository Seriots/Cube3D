/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_startscreen_event.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:25:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 13:27:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

#include <X11/keysym.h>

int	startscreen_key_press(KeySym keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}

int	startscreen_key_release(KeySym keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	return (0);
}
