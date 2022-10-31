/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display_wall.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:08:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 05:43:29 by pierre-yves      ###   ########.fr       */
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

int	shade_pixel(t_game *game, int i, int j)
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
		light = game->display.light_mask[j][i] * 2
			/ (game->display.screen[j][i].dist
			* game->display.screen[j][i].dist);
		light = max(light, 0.15);
		light = min(light, 2);
	}
	r = min(255, light * ((game->display.screen[j][i].color & 0xFF0000) >> 16));
	g = min(255, light * ((game->display.screen[j][i].color & 0X00FF00) >> 8));
	b = min(255, light * (game->display.screen[j][i].color & 0X0000FF));
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
		return (set_screen_data(&game->display.screen[p.y][p.x],
			display->fc_dist[p.y], get_ceil_color(game, p.y, display, 0)));
	else if (p.y > display->max)
		return (set_screen_data(&game->display.screen[p.y][p.x],
			display->fc_dist[p.y], get_floor_color(game, p.y, display, 0)));
	else
		return (set_screen_data(&game->display.screen[p.y][p.x],
			wall->dist, get_wall_color(p.y, display)));
	return (0);
}

int	display_wall_loop(t_game *game, t_wall *wall, t_point p)
{
	int	color;

	while (p.y < WIN_HEIGHT)
	{
		get_pixel_color(game, wall, p, &game->display);
		p.y++;
	}
	return (0);
	(void)color;
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
