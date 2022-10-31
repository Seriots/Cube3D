/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_seed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:52:04 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:43:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"
#include "mlx.h"

int	get_seed_text(char path[256], t_seed *seed)
{
	if (seed->tmp_value == 0)
		ft_strlcpy(path, "Random", 7);
	else
		ft_itoal_noalloc(path, seed->tmp_value);
	return (0);
}

int	display_seed_text(t_game *game, t_seed *seed)
{
	char	path[256];

	get_seed_text(path, seed);
	mlx_string_put(game->mlx.display, game->mlx.window,
		seed->box.x_text, seed->box.y_text,
		0xAAAAAA, seed->box.description);
	mlx_string_put(game->mlx.display, game->mlx.window,
		seed->box.x + 8, seed->box.y_text,
		0xAAAAAA, path);
	return (0);
}
