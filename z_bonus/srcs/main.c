/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/08 23:17:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_parsing.h"
#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "mzg_incs.h"

#include "ft.h"

/*ft_printarray(game.map.map, 0);
*/
int	main(int argc, char *argv[])
{
	t_game	game;
	int		error;

	if (argc > 2)
		return (display_error(1));
	if (argc == 2)
	{
		game.map.all_objects = 0;
		error = parsing(&(game.map), argv[argc - 1]);
		if (error)
			return (free_map(&game.map), display_error(error));
	}
	if (argc == 1)
	{
		error = get_maze(&game.map, 50, 50 ,12);
		if (error)
			return (free_map(&game.map), display_error(error));
	}
	error = start_game(&game, argv[1]);
	if (error)
		return (free_game(&game), display_error(error));
	return (free_game(&game), 0);
}
