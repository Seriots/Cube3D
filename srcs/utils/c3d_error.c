/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:50:47 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/20 15:53:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft.h"

int	display_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	if (code == 1)
		ft_putstr_fd("Wrong arguments numbers\nUsage: ./cub3D <map.cub>\n", 2);
	else if (code == 2)
		ft_putstr_fd("Invalid description line\nUsage: One line of each element \
``NO, SO, WE, EA, F, C`` only !\n", 2);
	else if (code == 3)
		ft_putstr_fd("Invalid number of element in description line\n", 2);
	else if (code == 4)
		ft_putstr_fd("Map is only composed of these character: `` 01NSEW``\n", 2);
	else if (code == 5)
		ft_putstr_fd("Open Fail\n", 2);
	else if (code == 6)
		ft_putstr_fd("Not all description line are present\nUsage: One line of each element \
``NO, SO, WE, EA, F, C`` only !\n", 2);
	else if (code == 7)
		ft_putstr_fd("No map in file\n", 2);
	else if (code == 8)
		ft_putstr_fd("One player (only) is needed\n", 2);
	else if (code == 9)
		ft_putstr_fd("Map must be enclosed\n", 2);
	else if (code == 10)
		ft_putstr_fd("Malloc fail\n", 2);
	else if (code == 11)
		ft_putstr_fd("Invalid file extension\n", 2);
	return (code);
}