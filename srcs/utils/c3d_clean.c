/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 12:25:27 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

#include "ft.h"
#include "mlx.h"

void	free_map(t_map *map)
{
	ft_free_tab(map->map);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
}

void	free_images(t_game *game)
{
	if (game->all_img.no.img)
		mlx_destroy_image(game->mlx.display, game->all_img.no.img);
	if (game->all_img.so.img)
		mlx_destroy_image(game->mlx.display, game->all_img.so.img);
	if (game->all_img.ea.img)
		mlx_destroy_image(game->mlx.display, game->all_img.ea.img);
	if (game->all_img.we.img)
		mlx_destroy_image(game->mlx.display, game->all_img.we.img);
	if (game->all_img.menu_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.menu_img.img);
	if (game->all_img.screen_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.screen_img.img);
}

void	free_game(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx.display);
	mlx_mouse_show(game->mlx.display, game->mlx.window);
	free_map(&game->map);
	free_images(game);
	mlx_destroy_window(game->mlx.display, game->mlx.window);
	mlx_destroy_display(game->mlx.display);
	free(game->mlx.display);
}
