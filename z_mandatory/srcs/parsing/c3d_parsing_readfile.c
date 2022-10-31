/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_readfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:17:54 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:39:17 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"

#include "ft.h"

static int	get_elem(t_map *map, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (10);
	if (ft_arraylen(split) != 2)
		return (ft_free_tab(split), 3);
	if (ft_strcmp(split[0], "NO") == 0 && !map->no)
		map->no = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0 && !map->so)
		map->so = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0 && !map->we)
		map->we = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0 && !map->ea)
		map->ea = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "F") == 0 && map->f == -1)
		map->f = ft_color(split[1]);
	else if (ft_strcmp(split[0], "C") == 0 && map->c == -1)
		map->c = ft_color(split[1]);
	else
		return (ft_free_tab(split), 2);
	return (ft_free_tab(split), 0);
}

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
		return (free_map(map), 10);
	return (0);
}

static int	get_all_elem(t_map *map, char *line)
{
	int	error;

	if (ft_strlen(line) == 0 || is_only_set(line, " "))
		return (free(line), 0);
	else
	{
		if (is_only_set(line, " 01NSEW"))
			return (-1);
		error = get_elem(map, line);
		free(line);
		line = NULL;
		if (error)
			return (error);
	}
	return (0);
}

int	read_file(t_map *map, char *file, int size)
{
	int		fd;
	int		error;
	char	*line;

	error = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (5);
	while (error == 0 && get_next_line(fd, &line, 0) != 0)
		error = get_all_elem(map, line);
	if (error != -1 || line == NULL)
		return (error);
	error = get_map(fd, map, line, size);
	if (error)
		return (error);
	return (0);
}
