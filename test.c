/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/28 16:38:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"

#include <math.h>

#include <stdio.h>

int	sign(float x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

double	dabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

t_vector	get_next_wall( t_vector pre_pos)
{
	t_vector	result;
	double	dist_x;
	double	dist_y;
	
	if (cos(pre_pos.angle) > 0)
		dist_x = ((floor(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);	
	else
		dist_x = ((ceil(pre_pos.x / CASE_SIZE) + sign(cos(pre_pos.angle))) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);
	if (sin(pre_pos.angle) > 0)
		dist_y = ((ceil(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	else
		dist_y = ((floor(pre_pos.y / CASE_SIZE) - sign(sin(pre_pos.angle))) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);
	printf("dist_x = %f, dist_y = %f, sign: %d\n", dist_x, dist_y, sign(sin(pre_pos.angle)));
	if (dabs(dist_x) <= dabs(dist_y))
	{
		dist_x = dist_x * cos(pre_pos.angle) + pre_pos.x;
		dist_y = (dist_x - pre_pos.x) * -1 * tan(pre_pos.angle) + pre_pos.y; 
	}
	else
	{
		dist_y = dist_y * sin(pre_pos.angle) + pre_pos.y;
		dist_x = (dist_y - pre_pos.y) * -1 / tan(pre_pos.angle) + pre_pos.x;
	}
	result.angle = pre_pos.angle;
	result.x = dist_x;
	result.y = dist_y;
	return (result);
}

int main(void)
{
	t_vector	vec2;

	//vec2.x = -24.8;
	//vec2.y = 51.6;
	//vec2.angle = -M_PI / 3;
	//for (int i = 0; i < 10; i++)
	//{
	//	vec2 = get_next_wall(vec2);
	//	printf("vec2.x = %f, vec2.y = %f\n\n", vec2.x, vec2.y);
	//}
	double a = 64 * 1.0;
	printf ("%.20f\n", a);
}