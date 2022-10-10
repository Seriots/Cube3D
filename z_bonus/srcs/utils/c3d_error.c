/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:50:47 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 15:46:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "c3d_struct.h"

#include "ft.h"
#include "mlx.h"

int	display_error2(int code)
{
	if (code == 11)
		ft_putstr_fd("Invalid file extension\n", 2);
	else if (code == 12)
		ft_putstr_fd("Open Image Fail\n", 2);
	else if (code == 13)
		ft_putstr_fd("Mlx load Fail\n", 2);
	else if (code == 14)
		ft_putstr_fd("Window load Fail\n", 2);
	return (code);
}

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
		ft_putstr_fd("Map is only composed of these character: ` 01NSEW`\n", 2);
	else if (code == 5)
		ft_putstr_fd("Open Fail\n", 2);
	else if (code == 6)
		ft_putstr_fd("Not all description line are present\n \
Usage: One line of each element \
``NO, SO, WE, EA, F, C`` only !\n", 2);
	else if (code == 7)
		ft_putstr_fd("No map in file\n", 2);
	else if (code == 8)
		ft_putstr_fd("One player (only) is needed\n", 2);
	else if (code == 9)
		ft_putstr_fd("Map must be enclosed\n", 2);
	else if (code == 10)
		ft_putstr_fd("Malloc fail\n", 2);
	else
		display_error2(code);
	return (code);
}

char	*get_error2(int code)
{
	if (code == 11)
		return ("Invalid file extension");
	else if (code == 12)
		return ("Open Image Fail");
	else if (code == 13)
		return ("Mlx load Fail");
	else if (code == 14)
		return ("Window load Fail");
	else
		return ("An error occurred");
}

char	*get_error(int code)
{
	if (code == 1)
		return ("Wrong arguments numbersUsage: ./cub3D <map.cub>");
	else if (code == 2)
		return ("Invalid description lineUsage: One line of each element \
``NO, SO, WE, EA, F, C`` only !");
	else if (code == 3)
		return ("Invalid number of element in description line");
	else if (code == 4)
		return ("Map is only composed of these character: ` 01NSEW`");
	else if (code == 5)
		return ("Open Fail");
	else if (code == 6)
		return ("Not all description line are present \
Usage: One line of each element \
``NO, SO, WE, EA, F, C`` only !");
	else if (code == 7)
		return ("No map in file");
	else if (code == 8)
		return ("One player (only) is needed");
	else if (code == 9)
		return ("Map must be enclosed");
	else if (code == 10)
		return ("Malloc fail");
	else
		return (get_error2(code));
}

void	display_error_on_screen(t_game *game, char *error, int x, int y)
{
	mlx_string_put(game->mlx.display, game->mlx.window,
		x - (6 * ft_strlen(error) / 2), y, 0xFF0000, error);
}
