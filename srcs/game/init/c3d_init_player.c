/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 10:51:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

static float	get_rotation(char c)
{
	if (c == 'N')
		return (0);
	else if (c == 'S')
		return (180);
	else if (c == 'E')
		return (90);
	else if (c == 'W')
		return (270);
	return (0);
}

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
				player->pos.x = j * CASE_SIZE + CASE_SIZE / 2;
				player->pos.y = i * CASE_SIZE + CASE_SIZE / 2;
				player->pos.x = WIN_WIDTH / 2 - 25;
				player->pos.y = WIN_HEIGHT / 2 - 25;
				player->rot = get_rotation(map->map[i][j]);
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
