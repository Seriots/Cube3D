/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 21:10:14 by lgiband          ###   ########.fr       */
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

unsigned int	get_floor_color(t_game *game, int pixel,
	t_display *display, int start)
{
	void	*color;
	int		x;
	int		y;

	if (game->settings.show_fl_ce == 0 && !start)
		return (game->map.f);
	x = (int)(display->ray.x + display->fc_dist[pixel]
			* display->ray.angle.cos / display->angle);
	y = (int)(display->ray.y - display->fc_dist[pixel]
			* display->ray.angle.sin / display->angle);
	x = (x - (x / CASE_SIZE) * CASE_SIZE) * display->fl->width / CASE_SIZE;
	y = (y - (y / CASE_SIZE) * CASE_SIZE) * display->fl->height / CASE_SIZE;
	color = (display->fl->addr
			+ (y * display->fl->line_length
				+ x * display->fl->bits_per_pixel / 8));
	return (*(unsigned int *)(color));
}

unsigned int	get_ceil_color(t_game *game, int pixel,
	t_display *display, int start)
{
	void	*color;
	int		x;
	int		y;

	if (game->settings.show_fl_ce == 0 && !start)
		return (game->map.c);
	x = (int)(display->ray.x + display->fc_dist[pixel]
			* display->ray.angle.cos / display->angle);
	y = (int)(display->ray.y - display->fc_dist[pixel]
			* display->ray.angle.sin / display->angle);
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
