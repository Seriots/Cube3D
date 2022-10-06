/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:31:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:13:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"

#include <stdio.h>

int	event_mouse_move(int x, int y, t_game *game)
{
	if (game->fcts.mousemove_fct)
		return (game->fcts.mousemove_fct(x, y, game));
	return (0);
}

int	event_mouse_press(int button, int x, int y, t_game *game)
{
	if (game->fcts.mousepressed_fct)
		return (game->fcts.mousepressed_fct(button, x, y, game));
	return (0);
}

int	event_mouse_release(int button, int x, int y, t_game *game)
{
	if (game->fcts.mousereleased_fct)
		return (game->fcts.mousereleased_fct(button, x, y, game));
	return (0);
}
