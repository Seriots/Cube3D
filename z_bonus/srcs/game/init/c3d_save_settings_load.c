/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save_settings_load.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:13:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 17:36:52 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"

#include "ft.h"

#include <fcntl.h>
#include <stdlib.h>

int	sf(void *ptr, char *value)
{
	*(float *)ptr = (float)ft_atoi(value);
	return (0);
}

int	si(void *ptr, char *value)
{
	*(int *)ptr = ft_atoi(value);
	return (0);
}

int	ss(void *ptr, char *value)
{
	ft_strlcpy((char *)ptr, value, 256);
	return (0);
}

int	set_settings(t_game *game, char *key, char *value)
{
	const t_savset	all[] = {{VFPS, &game->settings.fps, sf},
		{VCAM_X, &game->settings.cam_sensibility_x, sf},
		{VCAM_Y, &game->settings.cam_sensibility_y, sf},
		{VRES, &game->settings.resolution, sf}, {VFOV, &game->settings.fov, sf},
		{VSCROLL_SPEED, &game->settings.scroll_speed, sf},
		{VLEFT, &game->settings.left, si}, {VRIGHT, &game->settings.right, si},
		{VFORWARD, &game->settings.forward, si},
		{VPAUSE, &game->settings.pause, si},
		{VCOLOR, &game->settings.color, si}, {VDROP, &game->settings.drop, si},
		{VINVERT_SCROLL, &game->settings.invert_scroll, si},
		{VINVERT_MOUSE, &game->settings.invert_mouse, si},
		{VSHOWFPS, &game->settings.show_fps, si},
		{VSHOWMINIMAP, &game->settings.show_mmap, si},
		{VSHOWSEED, &game->settings.show_seed, si},
		{VNO, &game->map.default_north, ss},
		{VSO, &game->map.default_south, ss},
		{VEA, &game->map.default_east, ss}, {VWE, &game->map.default_west, ss},
		{VFLOOR, &game->map.default_floor, ss},
		{VCEIL, &game->map.default_ceil, ss},
		{VINTER, &game->settings.interact, si},
		{V1, &game->settings.slot1, si}, {V2, &game->settings.slot2, si},
		{V3, &game->settings.slot3, si}, {V4, &game->settings.slot4, si},
		{V5, &game->settings.slot5, si}, {V6, &game->settings.slot6, si},
		{V7, &game->settings.slot7, si}, {V8, &game->settings.slot8, si}};
	unsigned int	i;
	
	i = 0;
	while (i < sizeof(all) / sizeof(t_savset))
	{
		if (ft_strcmp(all[i].tag, key) == 0)
			return (all[i].fct(all[i].ptr, value));
		i++;
	}
	return (0);
}

int	load_settings(t_game *game)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open("files/settings.txt", O_RDONLY);
	if (fd == -1)
		return (5);
	get_next_line(fd, &line);
	while (line)
	{
		split = ft_split(line, '=');
		if (split[0] && split[1])
			set_settings(game, split[0], split[1]);
		ft_free_tab(split);
		free(line);
		get_next_line(fd, &line);
	}
	return (0);
}