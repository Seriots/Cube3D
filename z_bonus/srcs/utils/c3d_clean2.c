/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:47:42 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/25 13:27:56 by lgiband          ###   ########.fr       */
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
	if (all_img->fl.img)
		mlx_destroy_image(game->mlx.display, all_img->fl.img);
	if (all_img->ce.img)
		mlx_destroy_image(game->mlx.display, all_img->ce.img);
	all_img->ce.img = 0;
	all_img->fl.img = 0;
	all_img->no.img = 0;
	all_img->so.img = 0;
	all_img->ea.img = 0;
	all_img->we.img = 0;
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

void	free_images2(t_game *game)
{
	if (game->all_img.menu_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.menu_img.img);
	if (game->all_img.screen_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.screen_img.img);
	if (game->all_img.minimap_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.minimap_img.img);
	if (game->all_img.end_img.img)
		mlx_destroy_image(game->mlx.display, game->all_img.end_img.img);
	if (game->all_img.loading.img)
		mlx_destroy_image(game->mlx.display, game->all_img.loading.img);
	if (game->all_img.score.img)
		mlx_destroy_image(game->mlx.display, game->all_img.score.img);
	if (game->all_img.leaderboard.img)
		mlx_destroy_image(game->mlx.display, game->all_img.leaderboard.img);
	if (game->all_img.return_arrow.img)
		mlx_destroy_image(game->mlx.display, game->all_img.return_arrow.img);
	if (game->all_img.game_over.img)
		mlx_destroy_image(game->mlx.display, game->all_img.game_over.img);
	if (game->all_img.endoor.img)
		mlx_destroy_image(game->mlx.display, game->all_img.endoor.img);
	if (game->all_img.all_cursor_img)
		free_img_array(game, &game->all_img.all_cursor_img, 8);
	if (game->all_img.all_number_img)
		free_img_array(game, &game->all_img.all_number_img, 10);
	free_object(game, game->all_img.omap);
}

void	free_images(t_game *game)
{
	if (game->all_img.all_ghost_img)
		free_img_array(game, &game->all_img.all_ghost_img, 16);
	if (game->all_img.all_loading_img)
		free_img_array(game, &game->all_img.all_loading_img, 15);
	if (game->all_img.all_door_img)
		free_img_array(game, &game->all_img.all_door_img, 9);
	if (game->all_img.start_no.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_no.img);
	if (game->all_img.start_so.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_so.img);
	if (game->all_img.start_ea.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_ea.img);
	if (game->all_img.start_we.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_we.img);
	if (game->all_img.start_fl.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_fl.img);
	if (game->all_img.start_ce.img)
		mlx_destroy_image(game->mlx.display, game->all_img.start_ce.img);
	free_object(game, game->all_img.key);
	free_object(game, game->all_img.flashlight);
	free_object(game, game->all_img.heal);
	free_object(game, game->all_img.fullheal);
	free_object(game, game->all_img.bonushp);
	free_object(game, game->all_img.energy);
	free_object(game, game->all_img.b_energy);
	free_object(game, game->all_img.hud);
	free_object(game, game->all_img.syringe);
}
