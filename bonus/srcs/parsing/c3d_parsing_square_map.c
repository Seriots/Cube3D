/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_square_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:10:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:13:45 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"

#include "ft.h"

static int	ft_complete(char *square_line, int width, char *line, char c)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		square_line[i] = line[i];
		i++;
	}
	while (i < width)
	{
		square_line[i] = c;
		i++;
	}
	return (0);
}

int	set_square_map(t_map *map)
{
	char	**square_map;
	int		i;

	square_map = ft_calloc(sizeof(char *), (map->height + 1));
	if (!square_map)
		return (10);
	i = 0;
	while (i < map->height)
	{
		square_map[i] = ft_calloc(sizeof(char), (map->width + 1));
		if (!square_map[i])
			return (ft_free_tab(square_map), 10);
		ft_complete(square_map[i], map->width, map->map[i], ' ');
		i++;
	}
	ft_free_tab(map->map);
	map->map = square_map;
	return (0);
}
