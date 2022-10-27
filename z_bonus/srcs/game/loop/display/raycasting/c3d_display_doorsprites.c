/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_doorsprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:05:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 13:05:46 by lgiband          ###   ########.fr       */
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

unsigned int	get_door_color(t_game *game, t_img_data *img, int j)
{
	void	*color;
	int		y;

	y = (int)((j - game->display.doormin) * img->height
			/ (game->display.doormax - game->display.doormin));
	color = (img->addr
			+ (y * img->line_length
				+ game->display.x * game->display.bpp));
	return (*(unsigned int *)color);
}

int	draw_door_vline(t_game *game, t_img_data *img, int i, double dist)
{
	unsigned int	color;
	t_point			p;
	int				j;

	j = max(ft_ceil(game->display.doormin) - 1, -1);
	while (++j < WIN_HEIGHT && j < game->display.doormax)
	{
		p.x = i;
		p.y = j;
		color = get_door_color(game, img, j);
		if (color != 0xFF000000)
			my_mlx_pixel_put(&game->all_img.screen_img, i, j,
				shade_pixel(game, color, dist, p));
	}
	return (0);
}

int	display_door_vline(t_game *game, t_door *door, int i)
{
	game->display.img = door->img;
	game->display.d = (i - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.doorangle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	game->display.doormin = (double)VIEW_HEIGHT / 2 - game->player.updown
		+ game->player.z - ((double)CASE_SIZE / 2 - game->player.updown)
		* game->settings.fov / (game->display.doorangle * (door->door.dist
				+ game->settings.fov / (game->display.doorangle)));
	game->display.doormax = -(double)VIEW_HEIGHT / 2 + game->player.updown
		- game->player.z - ((double)CASE_SIZE / 2 + game->player.updown)
		* game->settings.fov / (game->display.doorangle * (door->door.dist
				+ game->settings.fov / (game->display.doorangle)));
	game->display.doormin *= (double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.doormax *= -(double)WIN_HEIGHT / (double)VIEW_HEIGHT;
	game->display.x = (int)(door->door.dist_from_start
			* game->display.img->width / CASE_SIZE)
		% game->display.img->width;
	game->display.factor = game->display.img->height
		/ (game->display.doormax - game->display.doormin);
	game->display.bpp = game->display.img->bits_per_pixel / 8;
	draw_door_vline(game, game->display.img, i, door->door.dist);
	return (0);
}

void	display_all_door(t_game *game, t_point *p, double dist)
{
	while (--p->y >= 0)
	{
		if (game->display.doors[p->y]
			[p->x + game->display.vline].need_display
			&& game->display.doors[p->y]
			[p->x + game->display.vline].door.dist > dist)
		{
			display_door_vline(game, &game->display.doors[p->y]
			[p->x + game->display.vline], p->x + game->display.vline);
			game->display.doors[p->y]
			[p->x + game->display.vline].need_display = 0;
		}
	}
}
