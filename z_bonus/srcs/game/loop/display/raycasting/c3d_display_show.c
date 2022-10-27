/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_show.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:30:03 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 13:31:13 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include "ft.h"
#include "mlx.h"

int	show_fps(t_game *game)
{
	char	fps[32];

	ft_itoa_noalloc(fps, 1000 / game->delay);
	ft_strlcat(fps, " fps", 32);
	mlx_string_put(game->mlx.display, game->mlx.window, 10, 15, 0xFFFFFF, fps);
	return (0);
}

int	show_seed(t_game *game)
{
	char	seed[32];

	ft_itoal_noalloc(seed, game->settings.seed);
	mlx_string_put(game->mlx.display, game->mlx.window, WIN_WIDTH
		- 10 - (FONT_WIDTH * ft_strlen(seed)), 15, 0xFFFFFF, seed);
	return (0);
}

int	display_level(t_game *game)
{
	char	level[32];
	char	lvl[32];

	ft_itoa_noalloc(lvl, game->level);
	ft_strlcpy(level, "Level : ", 32);
	ft_strlcat(level, lvl, 32);
	mlx_string_put(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2 - (FONT_WIDTH * ft_strlen("Level : ") / 2),
		WIN_HEIGHT / 14, 0xDDDDDD, level);
	return (0);
}
