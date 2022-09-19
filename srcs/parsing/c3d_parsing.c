/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:03:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 16:55:58 by lgiband          ###   ########.fr       */
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

int	parsing(t_map *map, char *file)
{
	int	error;
	int	map_size;

	set_map(map);
	map_size = 0;
	error = set_map_size(file, &map_size);
	if (error)
		return (error);
	map->map = ft_calloc(sizeof(char *), map_size + 1);
	if (!map->map)
		return (10);
	error = read_file(map, file, map_size);
	if (error)
		return (error);
	error = check_map(map);
	if (error)
		return (error);
	return (0);
}
