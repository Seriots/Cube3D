/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_raycasting_display.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:24 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/29 16:37:51 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_utils.h"

#include <math.h>

unsigned int	get_wall_color(t_game *game, t_wall *wall, int pixel, double d)
{
	void	*color;
	int		x;
	int		y;
	int		min;
	int		max;

	min = WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT / ((wall->dist + game->settings.fov / cos(dabs(atan(d / game->settings.fov)))) * 2 * VIEW_SIZE * cos(dabs(atan(d / game->settings.fov))));
	max = WIN_HEIGHT - min;
	x = (int)wall->dist_from_start * game->all_img.no.width / CASE_SIZE;
	y = (int)((pixel - min) * game->all_img.no.height / (max - min));
	if (wall->face == 'N')
		color = (game->all_img.no.addr + (y * game->all_img.no.line_length
					+ x * (game->all_img.no.bits_per_pixel / 8)));
	else if (wall->face == 'S')
		color = (game->all_img.so.addr + (y * game->all_img.so.line_length
					+ x * (game->all_img.so.bits_per_pixel / 8)));
	else if (wall->face == 'W')
		color = (game->all_img.we.addr + (y * game->all_img.we.line_length
					+ x * (game->all_img.we.bits_per_pixel / 8)));
	else
		color = (game->all_img.ea.addr + (y * game->all_img.ea.line_length
					+ x * (game->all_img.ea.bits_per_pixel / 8)));
	return (*(unsigned int *)(color));
}

int	get_pixel_color(t_game *game, t_wall *wall, int y, int i)
{
	double	d;
	double	angle;

	d = (i - (double)WIN_WIDTH / 2.0) * (double)VIEW_SCREEN / (double)WIN_WIDTH;
	angle = dabs(atan(d / game->settings.fov));
	if (y < WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov * WIN_HEIGHT / ((wall->dist + game->settings.fov / cos(angle)) * 2 * VIEW_SIZE * cos(angle)))
		return (game->map.c);
	else if (WIN_HEIGHT - y < WIN_HEIGHT / 2 - CASE_SIZE * game->settings.fov
		* WIN_HEIGHT / ((wall->dist + game->settings.fov / cos(angle)) * 2 * VIEW_SIZE
			* cos(angle)))
		return (game->map.f);
	else
		return (get_wall_color(game, wall, y, d));
	return (0);
}

int	display_wall(t_game *game, t_wall *wall, int i)
{
	int	j;
	int	color;

	j = 0;
	while (j < WIN_HEIGHT)
	{
		color = get_pixel_color(game, wall, j, i);
		my_mlx_pixel_put(&game->all_img.screen_img, i, j, color);
		j++;
	}
	return (0);
}
