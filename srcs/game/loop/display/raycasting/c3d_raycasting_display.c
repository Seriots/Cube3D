/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/05 14:00:18 by lgiband          ###   ########.fr       */
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
	x = (int)(wall->dist_from_start * display.img->width / CASE_SIZE) % display.img->width;
	y = (int)((pixel - display.min) * display.img->height
			/ (display.max - display.min));
	color = (display.img->addr
			+ (y * display.img->line_length
				+ x * (display.img->bits_per_pixel / 8)));
	return (*(unsigned int *)(color));
}

int	get_pixel_color(t_game *game, t_wall *wall, t_point p, t_display display)
{
	if (p.y < display.min)
		return (game->map.c);
	else if (p.y > display.max)
		return (game->map.f);
	else
		return (get_wall_color(game, wall, p.y, display));
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	t_point		p;
	int			color;
	t_display	display;

	p.y = 0;
	p.x = i;
	display.img = get_image(&game->all_img, wall->face);
	display.d = (p.x - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_SCREEN / (double)WIN_WIDTH;
	display.angle = dabs(atan(display.d / game->settings.fov));
	display.min = WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT
		/ ((wall->dist + game->settings.fov / cos((display.angle)))
			* 2 * VIEW_SIZE * cos(display.angle));
	display.max = WIN_HEIGHT - display.min;
	while (p.y < WIN_HEIGHT)
	{
		color = get_pixel_color(game, wall, p, display);
		my_mlx_pixel_put(&game->all_img.screen_img, p.x, p.y, get_color(game, color));
		p.y++;
	}
	return (0);
}
