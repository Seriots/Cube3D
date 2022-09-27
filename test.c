/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:49:41 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/27 16:08:29 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"

#include <math.h>

#include <stdio.h>

int	get_next_wall(t_vector pre_pos)
{
	t_vector	result;
	double	dist_x;
	double	dist_y;
	
	dist_x = (((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.x) / cos(pre_pos.angle);	
	dist_y = (((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.y) / sin(pre_pos.angle);	
	printf("dist_x: %f, dist_y %f\n", dist_x, dist_y);
	if (dist_x < dist_y)
	{
		dist_x = ((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE;	
		dist_y = (((int)(pre_pos.x / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.x) * tan(pre_pos.angle) + pre_pos.y; 
	}
	else
	{
		dist_y = ((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE;	
		dist_x = (((int)(pre_pos.y / CASE_SIZE) + 1) * CASE_SIZE - pre_pos.y) / tan(pre_pos.angle) + pre_pos.x;
	}
	printf("dist_x: %f, dist_y %f\n", dist_x, dist_y);
	return (0);
}

int main(void)
{
	t_vector	vec;

	vec.x = 63.99;
	vec.y = 64.0;
	vec.angle = M_PI / 4
	;
	get_next_wall(vec);
}