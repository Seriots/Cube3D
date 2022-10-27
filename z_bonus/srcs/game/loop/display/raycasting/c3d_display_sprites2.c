/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_display_sprites2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:18:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/27 13:19:36 by lgiband          ###   ########.fr       */
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

unsigned int	damaged_ghost(t_object *obj, unsigned int color)
{
	double	damage;
	double	max;
	int		r;

	max = 100;
	damage = obj->use_count / (double)obj->use_max * max;
	r = (int)(color >> 16) + (int)damage;
	if (r > 255)
		r = 255;
	return ((r << 16) + (color & 0x00FF00) + (color & 0x0000FF));
}

unsigned int	get_sprite_color(t_game *game, t_object *obj,
					t_point p, int width)
{
	void	*color;
	int		x;
	int		y;

	x = (p.x * obj->game_img->width) / width;
	y = (p.y * obj->game_img->height) / (game->display.max - game->display.min);
	color = (obj->game_img->addr
			+ (y * obj->game_img->line_length
				+ x * obj->game_img->bits_per_pixel / 8));
	if (*(unsigned int *)color != 0xFF000000 && !ft_strcmp(obj->tag, GHOST))
		return (damaged_ghost(obj, *(unsigned int *)color));
	else
		return (*(unsigned int *)color);
}


int	check_angle(double angle, double left_angle, double right_angle)
{
	if (angle < left_angle && angle > right_angle)
		return (1);
	if (angle + 2 * M_PI < left_angle && angle + 2 * M_PI > right_angle)
		return (1);
	if (angle - 2 * M_PI < left_angle && angle - 2 * M_PI > right_angle)
		return (1);
	return (0);
}

double	get_dist_obj(t_game *game, t_object *obj)
{
	double	dist;

	obj->angle = get_obj_angle(obj->pos.x - game->display.xfov,
			-obj->pos.y + game->display.yfov);
	if (check_angle(obj->angle, game->display.left_angle,
			game->display.right_angle) == 0)
		return (-1.0);
	dist = sqrt(pow(obj->pos.x - game->display.xfov, 2)
			+ pow(obj->pos.y - game->display.yfov, 2));
	if (dist <= game->settings.fov
		/ cos(dabs(obj->angle - game->player.plane.value)))
		return (-1.0);
	dist -= game->settings.fov
		/ cos(dabs(obj->angle - game->player.plane.value));
	return (dist);
}

int	get_all_obj_dist(t_game *game)
{
	t_dict		*tmp;
	t_object	*obj;

	tmp = game->map.all_objects;
	while (tmp)
	{
		obj = tmp->value;
		obj->dist = get_dist_obj(game, obj);
		tmp = tmp->next;
	}
	return (0);
}
