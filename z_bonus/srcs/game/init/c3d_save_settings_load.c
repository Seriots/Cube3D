/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save_settings_load.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:13:27 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/11 13:53:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"

#include "ft.h"

#include <fcntl.h>
#include <stdlib.h>

int	set_settings(t_game *game, char *key, char *value)
{
	if (ft_strcmp(key, VFPS) == 0)
		game->settings.fps = (float)ft_atoi(value);
	else if (ft_strcmp(key, VCAM_X) == 0)
		game->settings.cam_sensibility_x = (float)ft_atoi(value);
	else if (ft_strcmp(key, VCAM_Y) == 0)
		game->settings.cam_sensibility_y = (float)ft_atoi(value);
	else if (ft_strcmp(key, VRES) == 0)
		game->settings.resolution = (float)ft_atoi(value);
	else if (ft_strcmp(key, VFOV) == 0)
		game->settings.fov = (float)ft_atoi(value);
	else if (ft_strcmp(key, VSCROLL_SPEED) == 0)
		game->settings.scroll_speed = (float)ft_atoi(value);
	else if (ft_strcmp(key, VLEFT) == 0)
		game->settings.left = ft_atoi(value);
	else if (ft_strcmp(key, VRIGHT) == 0)
		game->settings.right = ft_atoi(value);
	else if (ft_strcmp(key, VFORWARD) == 0)
		game->settings.forward = ft_atoi(value);
	else if (ft_strcmp(key, VBACKWARD) == 0)
		game->settings.backward = ft_atoi(value);
	else if (ft_strcmp(key, VPAUSE) == 0)
		game->settings.pause = ft_atoi(value);
	else if (ft_strcmp(key, VCOLOR) == 0)
		game->settings.color = ft_atoi(value);
	else if (ft_strcmp(key, VINVERT_SCROLL) == 0)
		game->settings.invert_scroll = ft_atoi(value);
	else if (ft_strcmp(key, VINVERT_MOUSE) == 0)
		game->settings.invert_mouse = ft_atoi(value);
	else if (ft_strcmp(key, VSHOWFPS) == 0)
		game->settings.show_fps = ft_atoi(value);
	else if (ft_strcmp(key, VSHOWMINIMAP) == 0)
		game->settings.show_mmap = ft_atoi(value);
	else if (ft_strcmp(key, VSHOWSEED) == 0)
		game->settings.show_seed = ft_atoi(value);
	else if (ft_strcmp(key, VNO) == 0)
		ft_strlcpy(game->map.default_north, value, 256);
	else if (ft_strcmp(key, VSO) == 0)
		ft_strlcpy(game->map.default_south, value, 256);
	else if (ft_strcmp(key, VWE) == 0)
		ft_strlcpy(game->map.default_west, value, 256);
	else if (ft_strcmp(key, VEA) == 0)
		ft_strlcpy(game->map.default_east, value, 256);
	else if (ft_strcmp(key, VFLOOR) == 0 )
		ft_strlcpy(game->map.default_floor, value, 256);
	else if (ft_strcmp(key, VCEIL) == 0)
		ft_strlcpy(game->map.default_ceil, value, 256);
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