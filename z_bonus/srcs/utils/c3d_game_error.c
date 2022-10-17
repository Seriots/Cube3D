/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:21:08 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 14:22:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"

#include "ft.h"

int	set_error_message(t_game *game, char *message, int duration)
{
	game->error.duration = duration;
	ft_strlcpy(game->error.message, message, 256);
	game->error.start_time = timestamp_msec(0);
	return (0);
}