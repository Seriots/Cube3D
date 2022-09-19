/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:19:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 14:23:30 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "c3d_parsing.h"
#include "c3d_struct.h"

#include "ft.h"

void	set_map(t_map *map)
{
	map->map = 0;
	map->NO = 0;
	map->SO = 0;
	map->WE = 0;
	map->EA = 0;
	map->F = -1;
	map->C = -1;
}

int	set_map_size(char *file, int *size)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = 0;
	if (fd == -1)
		return (5);
	while (get_next_line(fd, &line) != 0)
	{
		if (is_only_set(line, " 01NSEW"))
			break ;
		free(line);
	}
	while (line)
	{
		if (is_only_set(line, " 01NSEW"))
			*size += 1;
		else
			break ;
		free(line);
		get_next_line(fd, &line);
	}
	if (line != 0)
		return (free(line), close(fd), 4);
	return (close(fd), 0);
}
