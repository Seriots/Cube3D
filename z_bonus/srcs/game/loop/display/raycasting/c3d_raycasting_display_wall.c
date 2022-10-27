/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display_wall.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:08:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 21:10:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_object.h"

#include "ft.h"

#include <math.h>

#include <stdio.h>

int	shade_pixel(t_game *game, int color, double dist, t_point p)
{
	int		r;
	int		g;
	int		b;
	double	light;

	(void)game;
	if (!is_lamp(game))
		light = 0.15;
	else
	{
		light = game->display.light_mask[p.y][p.x] * 2 / (dist * dist);
		light = max(light, 0.15);
		light = min(light, 2);
	}
	r = min(255, light * ((color & 0xFF0000) >> 16));
	g = min(255, light * ((color & 0X00FF00) >> 8));
	b = min(255, light * (color & 0X0000FF));
	return ((r << 16) | (g << 8) | b);
}

int	shade_pixel_sprite(t_game *game, int color, double dist, t_point p)
{
	int		r;
	int		g;
	int		b;
	double	light;

	(void)game;
	if (!is_lamp(game))
		light = 0.15;
	else
	{
		light = game->display.light_mask[p.y][p.x] * 1 / (dist * dist);
		light = max(light, 0.15);
		light = min(light, 1.0);
	}
	r = min(255, light * ((color & 0xFF0000) >> 16));
	g = min(255, light * ((color & 0X00FF00) >> 8));
	b = min(255, light * (color & 0X0000FF));
	return ((r << 16) | (g << 8) | b);
}

int	get_pixel_color(t_game *game, t_wall *wall, t_point p, t_display *display)
{
	if (p.y < display->min)
		return (shade_pixel(game, get_floor_color(game, p.y, display, 0),
				display->fc_dist[p.y], p));
	else if (p.y > display->max)
		return (shade_pixel(game, get_ceil_color(game, p.y, display, 0),
				display->fc_dist[p.y], p));
	else
		return (shade_pixel(game, get_wall_color(p.y, display), wall->dist, p));
	return (0);
}

int	display_wall_loop(t_game *game, t_wall *wall, t_point p)
{
	int	color;

	while (p.y < WIN_HEIGHT)
	{
		color = get_pixel_color(game, wall, p, &game->display);
		my_mlx_pixel_put(&game->all_img.screen_img,
			p.x, p.y, get_color(game->settings.color, color));
		p.y++;
	}
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	t_point		p;

	p = (t_point){.x = i, .y = 0};
	game->display.img = get_image(&game->all_img, wall->face);
	game->display.d = (p.x - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown
		+ game->player.z - ((double)CASE_SIZE / 2 - game->player.updown)
		* game->settings.fov / (game->display.angle
			* (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown
		- game->player.z - ((double)CASE_SIZE / 2 + game->player.updown)
		* game->settings.fov / (game->display.angle
			* (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.x = (int)(wall->dist_from_start
			* game->display.img->width / CASE_SIZE) % game->display.img->width;
	game->display.factor = game->display.img->height
		/ (game->display.max - game->display.min);
	game->display.bpp = game->display.img->bits_per_pixel / 8;
	display_wall_loop(game, wall, p);
	return (0);
}
