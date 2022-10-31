/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:08:53 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 10:59:43 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_init.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_startscreen.h"
#include "mzg_incs.h"

#include "ft.h"

#include <stdlib.h>

double	get_light_value(int i, int j)
{
	double	dist_center;

	dist_center = sqrt(pow(i - WIN_WIDTH / 2, 2) + pow(j - WIN_HEIGHT / 2, 2));
	if (dist_center > 400)
		return (0.0);
	if (dist_center < 0)
		return (1);
	return (1 - (1 - 0.0) * sqrt((dist_center - 0) / (400)));
}

int	init_light(t_display *display)
{
	int	j;
	int	i;

	j = -1;
	display->light_mask = ft_calloc(WIN_HEIGHT, sizeof(double *));
	if (!display->light_mask)
		return (10);
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		display->light_mask[j] = ft_calloc(WIN_WIDTH, sizeof(double));
		if (!display->light_mask[j])
			return (10);
		while (++i < WIN_WIDTH)
			display->light_mask[j][i] = 80000 * pow(get_light_value(i, j), 2);
	}
	return (0);
}

int	init_display(t_display *display)
{
	int	j;

	display->doors = ft_calloc(sizeof(t_door_data), WIN_WIDTH + 1);
	if (!display->doors)
		return (10);
	j = -1;
	while (++j < WIN_WIDTH + 1)
	{
		display->doors[j].door_tab = ft_calloc(sizeof(t_door), 20);
		if (!display->doors[j].door_tab)
			return (10);
	}
	display->screen = ft_calloc(sizeof(t_screen_data *), WIN_HEIGHT);
	if (!display->screen)
		return (10);
	j = -1;
	while (++j < WIN_HEIGHT)
	{
		display->screen[j] = ft_calloc(sizeof(t_screen_data), WIN_WIDTH);
		if (!display->screen[j])
			return (10);
	}
	return (init_light(display));
}
