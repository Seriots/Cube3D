/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:19:52 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 15:04:35 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "c3d_parsing.h"
#include "c3d_struct.h"

#include "ft.h"

#include <stdio.h>

void	set_map(t_map *map)
{
	map->map = 0;
	map->height = 0;
	map->width = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->f = -1;
	map->c = -1;
}

int	set_map_size(char *file, int *size)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = 0;
	if (fd == -1)
		return (5);
	while (get_next_line(fd, &line, 0) != 0)
	{
		if (is_only_set(line, " 0123NSEW"))
			break ;
		free(line);
	}
	while (line)
	{
		if (is_only_set(line, " 0123NSEW"))
			*size += 1;
		else
			break ;
		free(line);
		get_next_line(fd, &line, 0);
	}
	get_next_line(fd, &line, 1);
	if (line != 0)
		return (free(line), close(fd), 4);
	return (close(fd), 0);
}
