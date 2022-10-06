/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:12:19 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 13:14:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_utils.h"

int	game_loop(t_game *game)
{
	if (game->fcts.update_fct)
		game->fcts.update_fct(game);
	if (game->fcts.display_fct)
		game->fcts.display_fct(game);
	return (0);
}
