/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_doorsprites.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:05:02 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:51:00 by lgiband          ###   ########.fr       */
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

	y = (int)((j - game->display.doormin) * game->display.factor);
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
	int				displaymax;

	j = max(ft_ceil(game->display.doormin) - 1, -1);
	displaymax = min(WIN_HEIGHT, game->display.doormax);
	while (++j < displaymax)
	{
		p.x = i;
		p.y = j;
		color = get_door_color(game, img, j);
		if (color != 0xFF000000)
			set_screen_data(&game->display.screen[j][i], dist, color);
	}
	return (0);
	(void)p;
}

int	display_door_vline(t_game *game, t_door *door, int i)
{
	double	factor;

	game->display.img = door->img;
	game->display.d = (i - (double)WIN_WIDTH / 2.0)
		* (double)VIEW_WIDTH / (double)WIN_WIDTH;
	game->display.doorangle = 1
		/ sqrt(1 + pow(game->display.d / game->settings.fov, 2));
	factor = game->settings.fov / (game->display.doorangle * (door->door.dist
				+ game->settings.fov / (game->display.doorangle)));
	game->display.doormin = (double)VIEW_HEIGHT / 2 - game->player.updown
		+ game->player.z - ((double)CASE_SIZE / 2 - game->player.updown)
		* factor;
	game->display.doormax = -(double)VIEW_HEIGHT / 2 + game->player.updown
		- game->player.z - ((double)CASE_SIZE / 2 + game->player.updown)
		* factor;
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
		if (game->display.doors
			[p->x + game->display.vline].door_tab[p->y].need_display
			&& game->display.doors
			[p->x + game->display.vline].door_tab[p->y].door.dist <= dist)
			break ;
		display_door_vline(game, &game->display.doors
		[p->x + game->display.vline].door_tab[p->y],
			p->x + game->display.vline);
		game->display.doors
		[p->x + game->display.vline].door_tab[p->y].need_display = 0;
	}
	game->display.doors[p->x + game->display.vline].door_max = p->y + 1;
}
