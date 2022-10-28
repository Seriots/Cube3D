/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_readfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:17:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/28 11:35:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"

#include "ft.h"
#include <stdio.h>

static int	get_map(int fd, t_map *map, char *line, int size)
{
	int	i;

	i = 0;
	map->width = ft_strlen(line);
	while (line)
	{
		map->map[i] = line;
		if (line && (int)ft_strlen(line) > map->width)
			map->width = ft_strlen(line);
		get_next_line(fd, &line, 0);
		i++;
	}
	if (i != size)
		return (10);
	return (0);
}

static int	get_all_elem(t_game *game, t_map *map, char **line)
{
	int	error;

	if (ft_strlen(*line) == 0 || is_only_set(*line, " \t\n\r\v\f"))
		return (free(*line), 0);
	else
	{
		if (is_only_set(*line, " 1"))
			return (-1);
		error = get_elem(game, map, *line);
		free(*line);
		*line = NULL;
		if (error)
			return (error);
	}
	return (0);
}

int	read_file(t_game *game, t_map *map, char *file, int size)
{
	int		fd;
	int		error;
	char	*line;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (5);
	while (error == 0 && get_next_line(fd, &line, 0) != 0)
		error = get_all_elem(game, map, &line);
	if (error != -1 || line == NULL)
		return (error);
	error = get_map(fd, map, line, size);
	if (error)
		return (free_map(game, map), error);
	return (0);
}
