/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_display_sprites.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/24 20:04:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include "dict.h"

#include "mlx.h"

#include <math.h>

#include <stdio.h>

int	start_draw_sprite_vline(t_game *game, t_img_data *img, int i, int width)
{
	int				j;
	t_point			p;
	unsigned int	color;

	j = game->display.min - 1;
	while (++j < WIN_HEIGHT && j < game->display.max)
	{
		if (j < 0)
			continue ;
		p.x = i - game->display.vline + width / 2;
		p.y = j - game->display.min;
		color = get_sprite_color(game, img, p, width);
		if (color != 0xFF000000)
			my_mlx_pixel_put(&game->all_img.screen_img, i, j, color);
	}
	return (0);
}

static void	start_set_display_sprite(t_game *game, t_object *obj, double dist)
{
	game->display.d = (game->display.vline - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->start_map.player.updown
		+ game->start_map.player.z
		- ((double)CASE_SIZE / 2 - game->start_map.player.updown)
		* game->settings.fov / (game->display.angle
			* (dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->start_map.player.updown
		- game->start_map.player.z
		- ((double)CASE_SIZE / 2 + game->start_map.player.updown)
		* game->settings.fov / (game->display.angle
			* (dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.min = game->display.max
		- (game->display.max - game->display.min) * obj->height / CASE_SIZE;
}

int	start_display_sprite(t_game *game, t_object *obj, double dist, double angle)
{
	double	sprite_width;
	int		i;

	game->display.vline = -game->settings.fov * tan(angle)
		* (double)WIN_WIDTH / (double)VIEW_WIDTH + (double)WIN_WIDTH / 2;
	sprite_width = (((double)WIN_WIDTH / (double)VIEW_WIDTH) * obj->width)
		* game->settings.fov / (dist + game->settings.fov / cos(angle));
	i = -sprite_width / 2;
	start_set_display_sprite(game, obj, dist);
	while (i < sprite_width / 2)
	{
		if (i + game->display.vline >= 0 && i + game->display.vline < WIN_WIDTH)
		{
			if (game->display.wall_dist[i + game->display.vline] > dist)
				start_draw_sprite_vline(game, obj->game_img,
					i + game->display.vline, sprite_width);
		}
		i++;
	}
	return (0);
}

int	start_get_all_obj_dist(t_game *game)
{
	t_dict		*tmp;
	t_object	*obj;

	tmp = game->start_map.map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		obj->dist = start_get_dist_obj(game, obj);
		tmp = tmp->next;
	}
	return (0);
}

int	start_display_all_sprites(t_game *game)
{
	t_dict		*tmp;
	t_object	*obj;

	game->display.xfov = game->start_map.player.pos.x - game->settings.fov
		* game->start_map.player.plane.cos;
	game->display.yfov = game->start_map.player.pos.y + game->settings.fov
		* game->start_map.player.plane.sin;
	game->display.left_angle = game->start_map.player.plane.value + M_PI / 2;
	game->display.right_angle = game->start_map.player.plane.value - M_PI / 2;
	start_get_all_obj_dist(game);
	dict_sort_fct(&game->start_map.map.all_objects, &cmp_obj_dist);
	tmp = game->start_map.map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && obj->dist >= 0 && obj->is_visible && obj->game_img)
			start_display_sprite(game, obj, obj->dist, obj->angle
				- game->start_map.player.plane.value);
		tmp = tmp->next;
	}
	return (0);
}
