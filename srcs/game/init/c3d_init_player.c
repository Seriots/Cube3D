/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/26 12:25:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

static void	set_player_coord(t_map *map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_isinset(map->map[i][j], "NSWE"))
			{
				player->x = j * CASE_SIZE + CASE_SIZE / 2;
				player->y = i * CASE_SIZE + CASE_SIZE / 2;
				player->dir = map->map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_player(t_game *game)
{
	set_player_coord(&game->map, &game->player);
	return (0);
}