/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:11:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 14:11:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_init.h"

#include "mlx.h"

int	start_game(t_game *game)
{
	int	error;

	error = init_mlx(game);
	if (error)
		return (error);
	error = init_game(game);
	if (error)
		return (error);
	mlx_loop(game->mlx.display);
	mlx_mouse_show(game->mlx.display, game->mlx.window);
	return (0);
}
