/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:17:26 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 13:01:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_init.h"

static int	set_default_fcts(t_game *game)
{
	game->fcts.update_fct = default_update;
	game->fcts.display_fct = default_display;
	game->fcts.keypressed_fct = default_key_press;
	game->fcts.keyreleased_fct = default_key_release;
	return (0);
}

int	init_game(t_game *game)
{
	int	error;

	set_default_fcts(game);
	error = init_player(game);
	if (error)
		return (error);
	error = init_images(game);
	if (error)
		return (error);
	return (0);
}
