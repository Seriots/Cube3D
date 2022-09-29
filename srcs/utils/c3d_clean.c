/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 17:53:07 by lgiband          ###   ########.fr       */
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

void	free_img_array(t_game *game, t_img_data **imgs_ptr, int number)
{
	int			i;
	t_img_data	*imgs;

	i = 0;
	imgs = *imgs_ptr;
	(void)game;
	while (i < number)
	{
		mlx_destroy_image(game->mlx.display, imgs[i].img);
		i++;
	}
	free(imgs);
	*imgs_ptr = NULL;
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
	if (game->all_img.minimap_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.minimap_img.img);
	free_img_array(game, &game->all_img.all_cursor_img, 8);
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
