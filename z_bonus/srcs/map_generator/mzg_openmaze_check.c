/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_openmaze_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:23:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 14:24:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mzg_incs.h"

#include "ft.h"

int	is_door(char **map, int x, int y)
{
	if (map[y + 1][x] == '/' || map[y + 1][x] == ' ')
		return (1);
	if (map[y][x + 1] == '/' || map[y][x + 1] == ' ')
		return (1);
	if (map[y - 1][x] == '/' || map[y - 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == '/' || map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int	is_aligned(char **map, int x, int y)
{
	if ((map[y - 1][x] == map[y + 1][x] && map[y - 1][x] != '+')
		|| (map[y][x - 1] == map[y][x + 1] && map[y][x - 1] != '+'))
		return (1);
	return (0);
}

char	is_between_room(char **map, int x, int y)
{
	char	tab[127];
	int		i;
	char	c;

	ft_bzero(tab, 127 * sizeof(char));
	if (map[y + 1][x] != '+')
		tab[(int)map[y + 1][x]] = 1;
	if (map[y][x + 1] != '+')
		tab[(int)map[y][x + 1]] = 1;
	if (map[y - 1][x] != '+')
		tab[(int)map[y - 1][x]] = 1;
	if (map[y][x - 1] != '+')
		tab[(int)map[y][x - 1]] = 1;
	c = 0;
	i = -1;
	while (++i < 127)
	{
		if (tab[i] == 1)
		{
			if (c != 0)
				return (0);
			c = i;
		}
	}
	return (c);
}

char	is_destroyable(char **map, int x, int y)
{
	char	c;

	if (is_door(map, x, y))
		return (0);
	if (!is_aligned(map, x, y))
		return (0);
	c = is_between_room(map, x, y);
	return (c);
}
