/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start_raycasting_display.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:22:00 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:42:15 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_object.h"

#include "ft.h"

#include <math.h>

t_img_data	*start_get_image(t_all_img *all_img, char c)
{
	if (c == 'N')
		return (&all_img->start_no);
	else if (c == 'S')
		return (&all_img->start_so);
	else if (c == 'E')
		return (&all_img->start_ea);
	else
		return (&all_img->start_we);
}

static void	set_display(t_game *game, t_wall *wall, t_point p)
{
	game->display.img = start_get_image(&game->all_img, wall->face);
	game->display.d = (p.x - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.angle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.min = (double)VIEW_HEIGHT / 2
		- game->start_map.player.updown
		+ game->start_map.player.z
		- ((double)CASE_SIZE / 2 - game->start_map.player.updown)
		* game->settings.fov / (game->display.angle
			* (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.max = -(double)VIEW_HEIGHT / 2 + game->start_map.player.updown
		- game->start_map.player.z
		- ((double)CASE_SIZE / 2 + game->start_map.player.updown)
		* game->settings.fov / (game->display.angle
			* (wall->dist + game->settings.fov / (game->display.angle)));
	game->display.min *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.max *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.x = (int)(wall->dist_from_start
			* game->display.img->width / CASE_SIZE)
		% game->display.img->width;
	game->display.factor = game->display.img->height
		/ (game->display.max - game->display.min);
	game->display.bpp = game->display.img->bits_per_pixel / 8;
}

int	get_pixel_color_start(t_game *game, t_wall *wall,
		t_point p, t_display *display)
{
	(void)wall;
	(void)game;
	if (p.y < display->min)
		return (get_ceil_color(game, p.y, display, 1));
	else if (p.y > display->max)
		return (get_floor_color(game, p.y, display, 1));
	else
		return (get_wall_color(p.y, display));
	return (0);
}

int	start_display_wall(t_game *game, t_wall *wall, int i)
{
	t_point		p;
	int			color;

	p.y = 0;
	p.x = i;
	set_display(game, wall, p);
	while (p.y < WIN_HEIGHT)
	{
		color = get_pixel_color_start(game, wall, p, &game->display);
		my_mlx_pixel_put(&game->all_img.screen_img,
			p.x, p.y, get_color(game->settings.color, color));
		p.y++;
	}
	return (0);
}
