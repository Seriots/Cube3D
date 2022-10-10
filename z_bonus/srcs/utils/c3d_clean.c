/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:13:57 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 11:25:59 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

#include "dict.h"
#include "ft.h"
#include "mlx.h"

void	free_textures(t_game *game, t_all_img *all_img)
{
	if (all_img->no.img)
		mlx_destroy_image(game->mlx.display, all_img->no.img);
	if (all_img->so.img)
		mlx_destroy_image(game->mlx.display, all_img->so.img);
	if (all_img->ea.img)
		mlx_destroy_image(game->mlx.display, all_img->ea.img);
	if (all_img->we.img)
		mlx_destroy_image(game->mlx.display, all_img->we.img);
}

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
	*map = (t_map){.map = 0, .no = 0, .so = 0, .we = 0, .ea = 0, .all_objects = 0};
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
		if (imgs[i].img)
			mlx_destroy_image(game->mlx.display, imgs[i].img);
		i++;
	}
	free(imgs);
	*imgs_ptr = NULL;
}

void	free_images(t_game *game)
{
	if (game->all_img.menu_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.menu_img.img);
	if (game->all_img.screen_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.screen_img.img);
	if (game->all_img.minimap_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.minimap_img.img);
	if (game->all_img.all_cursor_img)
		free_img_array(game, &game->all_img.all_cursor_img, 8);
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
