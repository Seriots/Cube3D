/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:51:13 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 13:47:04 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include "ft.h"

#include <stdio.h>

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
				player->plane.value = get_rotation(map->map[i][j]);
				player->plane.sin = sin(player->plane.value);
				player->plane.cos = cos(player->plane.value);
				player->plane.tan = player->plane.sin / player->plane.cos;
				player->updown = 0;
				player->z = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_player(t_game *game, t_map *map, t_player *player, int first)
{
	(void)game;
	set_player_coord(map, player);
	player->forward = 0;
	player->backward = 0;
	player->left = 0;
	player->right = 0;
	player->turn_right = 0;
	player->turn_left = 0;
	player->turn_up = 0;
	player->turn_down = 0;
	player->run = 0;
	player->crouch = 0;
	player->angleup = 0;
	player->elevation = 0;
	player->invincible_frames = 0;
	if (first)
	{
		player->max_life = 3;
		player->life = player->max_life;
		player->max_stamina = 100;
		player->stamina = player->max_stamina;
	}
	return (0);
}
