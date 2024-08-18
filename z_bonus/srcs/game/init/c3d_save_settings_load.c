/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save_settings_load.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:13:27 by lgiband           #+#    #+#             */
/*   Updated: 2024/08/18 12:42:58 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"
#include "c3d_utils.h"

#include "ft.h"

#include <fcntl.h>
#include <stdlib.h>

int	set_settings_2(t_game *game, char *key, char *value)
{
	const t_savset	all[] = {
	{VINVERT_SCROLL, &game->settings.invert_scroll, si},
	{VINVERT_MOUSE, &game->settings.invert_mouse, si},
	{VCAM_X, &game->settings.cam_sensibility_x, sf},
	{VCAM_Y, &game->settings.cam_sensibility_y, sf},
	{VSHOWMINIMAP, &game->settings.show_mmap, si},
	{VSHOWSEED, &game->settings.show_seed, si},
	{VSHOWFPS, &game->settings.show_fps, si},
	{VSHOWFLCE, &game->settings.show_fl_ce, si},
	{VFL, &game->map.default_floor_path, ss},
	{VCE, &game->map.default_ceil_path, ss},
	{VFORWARD, &game->settings.forward, si},
	{VBACKWARD, &game->settings.backward, si}};
	unsigned long	i;

	i = 0;
	while (i < sizeof(all) / sizeof(all[0]))
	{
		if (ft_strcmp(all[i].tag, key) == 0)
			return (all[i].fct(all[i].ptr, value));
		i++;
	}
	return (0);
}

int	set_settings(t_game *game, char *key, char *value)
{
	const t_savset	all[] = {{VSCROLL_SPEED, &game->settings.scroll_speed, sf},
	{VINTER, &game->settings.interact, si}, {VNAME, &game->settings.name, ssn},
	{VPAUSE, &game->settings.pause, si}, {VCEIL, &game->map.default_ceil, ss},
	{VNO, &game->map.default_north, ss}, {VSO, &game->map.default_south, ss},
	{VFLOOR, &game->map.default_floor, ss}, {VFPS, &game->settings.fps, sf},
	{VLEFT, &game->settings.left, si}, {VRIGHT, &game->settings.right, si},
	{VCOLOR, &game->settings.color, si}, {VDROP, &game->settings.drop, si},
	{VOSMODE, &game->settings.osmode, si},
	{VEA, &game->map.default_east, ss}, {VWE, &game->map.default_west, ss},
	{VRUN, &game->settings.run, si}, {VCR, &game->settings.crouch, si},
	{V1, &game->settings.slot1, si}, {V2, &game->settings.slot2, si},
	{V3, &game->settings.slot3, si}, {V4, &game->settings.slot4, si},
	{V5, &game->settings.slot5, si}, {V6, &game->settings.slot6, si},
	{V7, &game->settings.slot7, si}, {V8, &game->settings.slot8, si}};
	unsigned long	i;

	i = 0;
	while (i < sizeof(all) / sizeof(t_savset))
	{
		if (ft_strcmp(all[i].tag, key) == 0)
			return (all[i].fct(all[i].ptr, value));
		i++;
	}
	return (set_settings_2(game, key, value));
}

int	load_settings(t_game *game)
{
	char	**split;
	char	*line;
	int		fd;

	fd = open("files/settings.txt", O_RDONLY);
	if (fd == -1)
		return (5);
	get_next_line(fd, &line, 0);
	while (line)
	{
		split = ft_split(line, '=');
		if (split[0] && split[1])
			set_settings(game, split[0], split[1]);
		ft_free_tab(split);
		free(line);
		get_next_line(fd, &line, 0);
	}
	return (0);
}
