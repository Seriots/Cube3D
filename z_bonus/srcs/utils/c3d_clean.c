/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 12:23:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"
#include "mlx.h"

void	free_map(t_map *map)
{
	if (map->map)
		ft_free_tab(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->fl)
		free(map->fl);
	if (map->ce)
		free(map->ce);
	if (map->all_objects)
		dict_clear(map->all_objects, 0, free);
	map->map = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->all_objects = 0;
}

void	dict_clear_with_inventory(t_game *game, t_dict **dict)
{
	t_dict	*next;
	t_dict	*tmp;
	int		i;
	int		is_free;

	tmp = *dict;
	while (tmp)
	{
		i = 0;
		is_free = 1;
		while (i < game->inventory.size)
		{
			if (game->inventory.items[i] == tmp->value)
			{
				is_free = 0;
				break ;
			}
			i++;
		}
		next = tmp->next;
		if (is_free)
			dict_delone(dict, tmp, 0, free);
		tmp = next;
	}
}

void	free_map_with_inventory(t_game *game, t_map *map)
{
	(void)game;
	if (map->map)
		ft_free_tab(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->fl)
		free(map->fl);
	if (map->ce)
		free(map->ce);
	if (map->all_objects)
		dict_clear_with_inventory(game, &map->all_objects);
	map->map = 0;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
}

int	free_menu(t_menu *menu)
{
	dict_clear(menu->all_objects, 0, free);
	return (0);
}

void	free_game(t_game *game)
{
	system("pkill vlc");
	mlx_do_key_autorepeaton(game->mlx.display);
	if (HIDE)
		mlx_mouse_show(game->mlx.display, game->mlx.window);
	free(game->settings.map_path);
	free_images(game);
	free_menu(&game->menu);
	free_menu(&game->start_menu);
	free_menu(&game->end_menu);
	free_menu(&game->score_menu);
	free_map(&game->start_map.map);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
