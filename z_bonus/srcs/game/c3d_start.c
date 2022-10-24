/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:11:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 12:20:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_init.h"
#include "mzg_incs.h"
#include "c3d_settings.h"

#include "ft.h"

#include "mlx.h"

int	start_game(t_game *game, char **argv, int argc)
{
	int		error;
	char	*path;

	if (argc == 2)
		path = argv[argc - 1];
	else
		path = NULL;
	ft_memset(game, 0, sizeof(t_game));
	error = init_mlx(game);
	if (error)
		return (error);
	error = init_game(game, path);
	if (error)
		return (error);
	mlx_loop(game->mlx.display);
	return (0);
}
