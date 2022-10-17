/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/17 16:07:28 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"

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

void	free_object(t_game *game, t_img_data *data)
{
	if (data[0].img)
		mlx_destroy_image(game->mlx.display, data[0].img);
	if (data[1].img)
		mlx_destroy_image(game->mlx.display, data[1].img);
	if (data[2].img)
		mlx_destroy_image(game->mlx.display, data[2].img);
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
	free_object(game, game->all_img.key);
	free_object(game, game->all_img.flashlight);
	free_object(game, game->all_img.heal);
	free_object(game, game->all_img.fullheal);
	free_object(game, game->all_img.bonushp);
	free_object(game, game->all_img.energy);
	free_object(game, game->all_img.b_energy);
	free_object(game, game->all_img.hud);
}
