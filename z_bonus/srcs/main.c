/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 11:46:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_parsing.h"
#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_init.h"
#include "mzg_incs.h"

#include "ft.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		error;

	if (argc > 2)
		return (display_error(1));
	error = start_game(&game, argv, argc);
	if (error)
		return (free_game(&game), display_error(error));
	return (free_game(&game), 0);
}
