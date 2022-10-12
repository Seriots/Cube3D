/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save_settings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:29:25 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 21:00:19 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"

#include "ft.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	save_int(int fd, char *key, int value)
{
	char	str[256];

	if (sprintf(str, "%s=%d\n", key, value))
		write(fd, str, ft_strlen(str));
}

void	save_str(int fd, char *key, char *value)
{
	char	str[512];

	if (sprintf(str, "%s=%s\n", key, value))
		write(fd, str, ft_strlen(str));
}

void	save_color(int fd, char *key, int value)
{
	char	str[256];

	if (sprintf(str, "%s=%d,%d,%d\n", key, value / 256 / 256,
			(value / 256) % 256, value % 256))
		write(fd, str, ft_strlen(str));
}

int	save_settings2(t_game *game, int fd)
{
	save_str(fd, VNO, game->map.no);
	save_str(fd, VSO, game->map.so);
	save_str(fd, VWE, game->map.we);
	save_str(fd, VEA, game->map.ea);
	save_color(fd, VCEIL, game->map.c);
	save_color(fd, VFLOOR, game->map.f);
	save_int(fd, VINTER, (int)game->settings.interact);
	save_int(fd, VDROP, (int)game->settings.drop);
	save_int(fd, V1, (int)game->settings.slot1);
	save_int(fd, V2, (int)game->settings.slot2);
	save_int(fd, V3, (int)game->settings.slot3);
	save_int(fd, V4, (int)game->settings.slot4);
	save_int(fd, V5, (int)game->settings.slot5);
	save_int(fd, V6, (int)game->settings.slot6);
	save_int(fd, V7, (int)game->settings.slot7);
	save_int(fd, V8, (int)game->settings.slot8);
	return (0);
}

int	save_settings(t_game *game)
{
	int		fd;

	fd = open("files/settings.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (5);
	save_int(fd, VFOV, (int)game->settings.fov);
	save_int(fd, VCAM_X, (int)game->settings.cam_sensibility_x);
	save_int(fd, VCAM_Y, (int)game->settings.cam_sensibility_y);
	save_int(fd, VRES, (int)game->settings.resolution);
	save_int(fd, VFPS, (int)game->settings.fps);
	save_int(fd, VSCROLL_SPEED, (int)game->settings.scroll_speed);
	save_int(fd, VLEFT, (int)game->settings.left);
	save_int(fd, VRIGHT, (int)game->settings.right);
	save_int(fd, VFORWARD, (int)game->settings.forward);
	save_int(fd, VBACKWARD, (int)game->settings.backward);
	save_int(fd, VPAUSE, (int)game->settings.pause);
	save_int(fd, VCOLOR, (int)game->settings.color);
	save_int(fd, VINVERT_SCROLL, (int)game->settings.invert_scroll);
	save_int(fd, VINVERT_MOUSE, (int)game->settings.invert_mouse);
	save_int(fd, VSHOWFPS, (int)game->settings.show_fps);
	save_int(fd, VSHOWMINIMAP, (int)game->settings.show_mmap);
	save_int(fd, VSHOWSEED, (int)game->settings.show_seed);
	save_settings2(game, fd);
	close(fd);
	return (0);
}
