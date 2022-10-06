/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:03:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 13:14:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"
#include "c3d_init.h"

#include "ft.h"

int	check_file_extension(char *line)
{
	if (ft_strlen(line) >= 5
		&& ft_strncmp(line + ft_strlen(line) - 4, ".cub", 4) == 0
		&& line[ft_strlen(line) - 5] != '/')
		return (0);
	return (11);
}

int	parsing(t_map *map, char *file)
{
	int	error;

	set_map(map);
	error = check_file_extension(file);
	if (error)
		return (error);
	error = set_map_size(file, &map->height);
	if (error)
		return (error);
	map->map = ft_calloc(sizeof(char *), map->height + 1);
	if (!map->map)
		return (10);
	error = read_file(map, file, map->height);
	if (error)
		return (error);
	error = check_map(map);
	if (error)
		return (error);
	return (0);
}
