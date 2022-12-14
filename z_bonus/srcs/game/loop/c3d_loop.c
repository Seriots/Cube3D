/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:19 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:42:06 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_menu.h"

int	fps(t_game *game)
{
	long	new_frame;

	while (timestamp_msec(game->last_frame) < 1000 / game->settings.fps)
		usleep(1000);
	new_frame = timestamp_msec(0);
	game->delay = new_frame - game->last_frame;
	game->last_frame = new_frame;
	return (0);
}

int	game_loop(t_game *game)
{
	fps(game);
	if (game->fcts.update_fct)
		game->fcts.update_fct(game);
	if (game->fcts.display_fct)
		game->fcts.display_fct(game);
	return (0);
}
