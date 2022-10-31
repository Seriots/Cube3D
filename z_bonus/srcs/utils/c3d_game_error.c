/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:21:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:52:08 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"

#include "ft.h"
#include "mlx.h"

int	set_error_message(t_game *game, char *message, int duration)
{
	game->error.duration = duration;
	ft_strlcpy(game->error.message, message, 256);
	game->error.start_time = timestamp_msec(0);
	return (0);
}

int	display_game_error(t_game *game)
{
	if (game->error.start_time + game->error.duration > game->last_frame)
		mlx_string_put(game->mlx.display, game->mlx.window,
			WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen(game->error.message) / 2),
			5 * WIN_HEIGHT / 6, 0xFF0000, game->error.message);
	return (0);
}
