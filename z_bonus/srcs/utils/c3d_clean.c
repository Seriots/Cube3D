/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 15:49:21 by lgiband          ###   ########.fr       */
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
	if (map->all_objects)
		dict_clear(map->all_objects, 0, free);
	*map = (t_map){.map = 0, .no = 0, .so = 0,
		.we = 0, .ea = 0, .all_objects = 0};
}

int	free_menu(t_menu *menu)
{
	dict_clear(menu->all_objects, 0, free);
	return (0);
}

void	free_game(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx.display);
	if (HIDE)
		mlx_mouse_show(game->mlx.display, game->mlx.window);
	free(game->settings.map_path);
	free_images(game);
	free_menu(&game->menu);
	free_menu(&game->start_menu);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
