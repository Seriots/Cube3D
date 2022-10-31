/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:48:35 by pierre-yves       #+#    #+#             */
/*   Updated: 2022/10/31 05:40:47 by pierre-yves      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_object.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <math.h>

int	draw_sprite_vline(t_game *game, t_object *obj, int i, int width)
{
	int				j;
	t_point			p;
	t_point			p2;
	unsigned int	color;

	j = ft_ceil(game->display.min) - 1;
	while (++j < WIN_HEIGHT && j < game->display.max)
	{
		if (j < 0)
			continue ;
		p2.x = i;
		p2.y = j;
		p.x = i - game->display.vline + width / 2;
		p.y = j - game->display.min;
		color = get_sprite_color(game, obj, p, width);
		if (color != 0xFF000000)
			set_screen_data(&game->display.screen[j][i], obj->dist, color);
	}
	return (0);
	(void)p2;
}

void	display_sprite_loop(t_game *game, t_object *obj,
	double sprite_width, double dist)
{
	t_point	p;

	p.x = -sprite_width / 2 - 1;
	while (++p.x < sprite_width / 2)
	{
		if (p.x + game->display.vline >= 0
			&& p.x + game->display.vline < WIN_WIDTH)
		{
			p.y = game->display.doors[p.x + game->display.vline].door_max;
			if (game->display.wall_dist[p.x + game->display.vline] > dist)
			{
				display_all_door(game, &p, dist);
				draw_sprite_vline(game, obj,
					p.x + game->display.vline, sprite_width);
			}
		}
	}
}

int	display_sprite(t_game *game, t_object *obj, double dist, double angle)
{
	double	sprite_width;

	game->display.vline = -game->settings.fov * tan(angle) * (double)WIN_WIDTH
		/ (double)VIEW_WIDTH + (double)WIN_WIDTH / 2;
	sprite_width = (((double)WIN_WIDTH / (double)VIEW_WIDTH) * obj->width)
		* game->settings.fov
		/ ((dist + game->settings.fov / cos(angle)) * cos(angle));
	game->display.d = (game->display.vline - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown
		+ game->player.z - ((double)CASE_SIZE / 2 - game->player.updown)
		* game->settings.fov / (game->display.angle * (dist + game->settings.fov
				/ (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown
		- game->player.z - ((double)CASE_SIZE / 2 + game->player.updown)
		* game->settings.fov / (game->display.angle * (dist + game->settings.fov
				/ (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.min = game->display.max
		- (game->display.max - game->display.min) * obj->height / CASE_SIZE;
	display_sprite_loop(game, obj, sprite_width, dist);
	return (0);
}

int	display_restof_doors(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		j = game->display.doors[i].door_max;
		while (--j >= 0)
		{
			if (game->display.doors[i].door_tab[j].need_display)
			{
				display_door_vline(game, &game->display.doors[i].door_tab[j], i);
				game->display.doors[i].door_tab[j].need_display = 0;
			}
		}
	}
	return (0);
}

int	display_all_sprites(t_game *game)
{
	t_dict		*tmp;
	t_object	*obj;

	game->display.xfov = game->player.pos.x
		- game->settings.fov * game->player.plane.cos;
	game->display.yfov = game->player.pos.y
		+ game->settings.fov * game->player.plane.sin;
	game->display.left_angle = game->player.plane.value + M_PI / 2;
	game->display.right_angle = game->player.plane.value - M_PI / 2;
	get_all_obj_dist(game);
	dict_sort_fct(&game->map.all_objects, &cmp_obj_dist);
	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		if (obj && obj->dist >= 0 && obj->is_visible && obj->game_img)
			display_sprite(game, obj, obj->dist,
				obj->angle - game->player.plane.value);
		tmp = tmp->next;
	}
	display_restof_doors(game);
	return (0);
}
