/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/19 17:40:13 by ppajot           ###   ########.fr       */
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

t_img_data	*get_image(t_all_img *all_img, char c)
{
	if (c == 'N')
		return (&all_img->no);
	else if (c == 'S')
		return (&all_img->so);
	else if (c == 'E')
		return (&all_img->ea);
	else
		return (&all_img->we);
}

unsigned int	get_wall_color(int pixel, t_display *display)
{
	void	*color;
	int		y;

	y = (int)((pixel - display->min) * display->factor);
	color = (display->img->addr
			+ (y * display->img->line_length
				+ display->x * display->bpp));
	return (*(unsigned int *)(color));
}

unsigned int	get_floor_color(int pixel, t_display *display)
{
	void	*color;
	int		x;
	int		y;

	x = (int)(display->ray.x + display->fc_dist[pixel] * display->ray.angle.cos / display->angle);
	y = (int)(display->ray.y - display->fc_dist[pixel] * display->ray.angle.sin / display->angle);
	x = (x - (x / CASE_SIZE) * CASE_SIZE) * display->fl->width / CASE_SIZE;
	y = (y - (y / CASE_SIZE) * CASE_SIZE) * display->fl->height / CASE_SIZE;
	color = (display->fl->addr
			+ (y * display->fl->line_length
				+ x * display->fl->bits_per_pixel / 8));	
	return (*(unsigned int *)(color));
}

unsigned int	get_ceil_color(int pixel, t_display *display)
{
	void	*color;
	int		x;
	int		y;

	x = (int)(display->ray.x + display->fc_dist[pixel] * display->ray.angle.cos / display->angle);
	y = (int)(display->ray.y - display->fc_dist[pixel] * display->ray.angle.sin / display->angle);
	x = (x - (x / CASE_SIZE) * CASE_SIZE) * display->ce->width / CASE_SIZE;
	y = (y - (y / CASE_SIZE) * CASE_SIZE) * display->ce->height / CASE_SIZE;
	color = (display->ce->addr
			+ (y * display->ce->line_length
				+ x * display->ce->bits_per_pixel / 8));	
	return (*(unsigned int *)(color));
}

int	is_lamp(t_game *game)
{
	t_object	*obj;
	
	if (game->inventory.selected < 0)
		return (0);
	obj = game->inventory.items[game->inventory.selected];
	if (obj && !ft_strcmp(obj->tag, LAMP) && obj->state == 1)
		return (1);
	return (0);
}

int	shade_pixel(t_game *game, int color, double dist, t_point p)
{
	int	r;
	int	g;
	int	b;
	double	light;
	(void)game;
	//if (p.x == 500)
	//	printf("dist: %f\n", dist);
/*	if (is_lamp(game))
	{
		if (pow(p.x - WIN_WIDTH / 2, 2) + pow(p.y - WIN_HEIGHT / 2, 2) < 90000)
		{
			if (dist < 256)
				light = 1 - dist / (2 * 256);
			else
				light = 1 / 2 - (dist - 256) / (2 * dist);
			light = 1.0;
		}
		else
			light = 0.2;
		light = max(light, 0.1);
		light = min(light, 1);
	}
	else*/
		light = 1.0;
	r = light * ((color & 0xFF0000) >> 16);
	g = light * ((color & 0X00FF00) >> 8);
	b = light * (color & 0X0000FF);
	return ((r << 16) | (g << 8) | b);
	(void)dist;
	(void)p;
	return (color);
}

int	get_pixel_color(t_game *game, t_wall *wall, t_point p, t_display *display)
{
	if (p.y < display->min)
		return (shade_pixel(game, get_floor_color(p.y, display), display->fc_dist[p.y], p));
	else if (p.y > display->max)
		return (shade_pixel(game, get_ceil_color(p.y, display), display->fc_dist[p.y], p));
	else
		return (shade_pixel(game, get_wall_color(p.y, display), wall->dist, p));
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	t_point		p;
	int			color;

	p.y = 0;
	p.x = i;
	game->display.img = get_image(&game->all_img, wall->face);
	game->display.d = (p.x - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	//game->display.angle = cos(dabs(atan(game->display.d / game->settings.fov)));
	game->display.angle = 1 / sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown + game->player.z - ((double)CASE_SIZE / 2 - game->player.updown) * game->settings.fov / (game->display.angle * (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown - game->player.z - ((double)CASE_SIZE / 2 + game->player.updown) * game->settings.fov / (game->display.angle * (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.x = (int)(wall->dist_from_start * game->display.img->width / CASE_SIZE)
		% game->display.img->width;
	game->display.factor = game->display.img->height / (game->display.max - game->display.min);
	game->display.bpp = game->display.img->bits_per_pixel / 8;
	while (p.y < WIN_HEIGHT)
	{
		color = get_pixel_color(game, wall, p, &game->display);
		my_mlx_pixel_put(&game->all_img.screen_img,
			p.x, p.y, get_color(game->settings.color, color));
		p.y++;
	}
	return (0);
}
