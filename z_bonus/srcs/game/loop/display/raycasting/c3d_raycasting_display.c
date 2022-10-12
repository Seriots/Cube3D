/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre-yves <pierre-yves@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 22:38:43 by pierre-yves      ###   ########.fr       */
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

unsigned int	get_wall_color(t_game *game, t_wall *wall,
			int pixel, t_display display)
{
	void	*color;
	int		x;
	int		y;

	(void)game;
	x = (int)(wall->dist_from_start * display.img->width / CASE_SIZE)
		% display.img->width;
	y = (int)((pixel - display.min) * display.img->height
			/ (display.max - display.min));
	color = (display.img->addr
			+ (y * display.img->line_length
				+ x * (display.img->bits_per_pixel / 8)));
	return (*(unsigned int *)(color));
}

int	shade_pixel(int color, double dist, t_point p)
{
	int	r;
	int	g;
	int	b;
	double	light;

	//if (p.x == 500)
	//	printf("dist: %f\n", dist);
	//if (pow(p.x - WIN_WIDTH / 2, 2) + pow(p.y - WIN_HEIGHT / 2, 2) < 40000)
	//{
	//	//if (dist < 256)
	//	//	light = 1 - dist / (2 * 256);
	//	//else
	//	//	light = 1 / 2 - (dist - 256) / (2 * dist);
	//	light = 4 / sqrt(dist);
	//}
	//else
	(void)p;
	(void)dist;
		light = 0.1;
	light = max(light, 0.1);
	light = min(light, 1);
	r = (color & 0xFF0000) >> 16;
	g = (color & 0X00FF00) >> 8;
	b = color & 0X0000FF;
	r *= light;
	g *= light;
	b *= light;
	return ((r << 16) | (g << 8) | b);
}

int	get_pixel_color(t_game *game, t_wall *wall, t_point p, t_display display)
{
	if (p.y < display.min)
		return (shade_pixel(game->map.c, display.fc_dist[p.y], p));
	else if (p.y > display.max)
		return (shade_pixel(game->map.f, display.fc_dist[p.y], p));
	else
		return (shade_pixel(get_wall_color(game, wall, p.y, display), wall->dist, p));
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
	game->display.angle = dabs(atan(game->display.d / game->settings.fov));
	game->display.min = (double)VIEW_HEIGHT / 2 - game->player.updown + game->player.z - ((double)CASE_SIZE / 2 - game->player.updown) * game->settings.fov / (cos(game->display.angle) * (wall->dist + game->settings.fov / cos((game->display.angle))));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->player.updown - game->player.z - ((double)CASE_SIZE / 2 + game->player.updown) * game->settings.fov / (cos(game->display.angle) * (wall->dist + game->settings.fov / cos((game->display.angle))));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	while (p.y < WIN_HEIGHT)
	{
		color = get_pixel_color(game, wall, p, game->display);
		my_mlx_pixel_put(&game->all_img.screen_img,
			p.x, p.y, get_color(game, color));
		p.y++;
	}
	return (0);
}
