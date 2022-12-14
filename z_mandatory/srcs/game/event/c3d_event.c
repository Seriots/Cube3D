/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:59:18 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 11:31:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

#include "mlx.h"

int	event_key_press(KeySym keycode, t_game *game)
{
	if (game->fcts.keypressed_fct)
		return (game->fcts.keypressed_fct(keycode, game));
	return (0);
}

int	event_key_release(KeySym keycode, t_game *game)
{
	if (game->fcts.keyreleased_fct)
		return (game->fcts.keyreleased_fct(keycode, game));
	return (0);
}

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx.display);
	return (0);
}
