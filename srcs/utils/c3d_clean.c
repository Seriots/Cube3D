/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/19 11:16:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

#include "ft.h"

void	free_map(t_map *map)
{
	ft_free_tab(map->map);
	free(map->NO);
	free(map->SO);
	free(map->WE);
	free(map->EA);
}

void	free_game(t_game *game)
{
	free_map(&game->map);
}