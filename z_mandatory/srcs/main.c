/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 15:39:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_parsing.h"
#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		error;

	if (argc != 2)
		return (display_error(1));
	ft_memset(&game, 0, sizeof(t_game));
	error = parsing(&(game.map), argv[argc - 1]);
	if (error)
		return (free_map(&game.map), display_error(error));
	error = start_game(&game);
	if (error)
		return (free_game(&game), display_error(error));
	return (free_game(&game), 0);
}
