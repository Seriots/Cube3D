/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:46:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 11:32:20 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_parsing.h"
#include "c3d_struct.h"
#include "c3d_utils.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		error;

	if (argc != 2)
		return (display_error(1));
	error = parsing(&(game.map), argv[argc - 1]);
	if (error)
		return (display_error(error));
	return (0);
}
