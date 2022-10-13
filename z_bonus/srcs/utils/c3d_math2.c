/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:02:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 11:11:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include <math.h>

double	norm(double x, double y)
{
	return (sqrt(pow(x, 2.0) + pow(y, 2.0)));
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_in_circle(int x, int y, unsigned int color)
{
	int	dist_x;
	int	dist_y;

	dist_x = x - (MMAP_WIDTH / 2);
	dist_y = y - (MMAP_HEIGHT / 2);
	if (norm(dist_x, dist_y) < MMAP_HEIGHT / 2)
		return (color);
	return (0xFF000000);
}

double	dist_to_obj(t_coord player, t_coord obj)
{
	return (norm(player.x - obj.x, player.y - obj.y));
}
