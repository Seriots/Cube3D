/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/16 15:26:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

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

int	is_lamp(t_game *game)
{
	t_object	*obj;
	
	if (game->inventory.selected < 0)
		return (0);
	obj = game->inventory.items[game->inventory.selected];
	if (obj && obj->hand_img == &game->all_img.flashlight[1] && obj->state == 1)
		return (1);
	return (0);
}

int	shade_pixel(t_game *game, int color, double dist, t_point p)
{
	int	r;
	int	g;
	int	b;
	double	light;

	//if (p.x == 500)
	//	printf("dist: %f\n", dist);
	if (is_lamp(game))
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
	else
		light = 0.2;
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
		return (shade_pixel(game, game->map.c, display->fc_dist[p.y], p));
	else if (p.y > display->max)
		return (shade_pixel(game, game->map.f, display->fc_dist[p.y], p));
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
