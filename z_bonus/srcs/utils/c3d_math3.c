/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_math3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:09:37 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/20 10:18:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"

double	dist_to_obj(t_coord player, t_coord obj)
{
	return (norm(player.x - obj.x, player.y - obj.y));
}

double	get_obj_angle(double x, double y)
{
	double	angle;

	angle = atan(y / x);
	if (x < 0)
		angle += M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	cmp_obj_dist(t_dict *dict1, t_dict *dict2)
{
	t_object *obj1;
	t_object *obj2;

	obj1 = dict1->value;
	obj2 = dict2->value;
	if (obj1->dist > obj2->dist)
		return (-1);
	else if (obj1->dist < obj2->dist)
		return (1);
	return (0);
}
