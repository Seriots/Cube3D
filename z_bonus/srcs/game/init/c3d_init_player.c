/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 19:47:09 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

static float	get_rotation(char c)
{
	if (c == 'N')
		return (M_PI / 2);
	else if (c == 'S')
		return (M_PI * 1.5);
	else if (c == 'W')
		return (M_PI);
	else if (c == 'E')
		return (0);
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
				player->angle_plane = get_rotation(map->map[i][j]);
				player->updown = 0;
				player->z = 0;
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
	game->player.forward = 0;
	game->player.backward = 0;
	game->player.left = 0;
	game->player.right = 0;
	game->player.turn_right = 0;
	game->player.turn_left = 0;
	game->player.turn_up = 0;
	game->player.turn_down = 0;
	return (0);
}
