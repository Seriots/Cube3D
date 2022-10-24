/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_endmenu_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:34:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 11:14:39 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_loop.h"
#include "c3d_menu.h"
#include "c3d_startscreen.h"
#include "c3d_utils.h"

#include "dict.h"
#include "ft.h"

#include "mlx.h"

#include <stdio.h>

int	display_one_stat(t_game *game, const t_tagint *stat, int y)
{
	char	str[40];
	int		size;
	int		i;

	if (y > (15 * MENU_HEIGHT / 100) + 13 && y < (MENU_HEIGHT - (15 * MENU_HEIGHT / 100)))
	{
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) + 20,
			(WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) + y, 0xDDDDDD, (char *)stat->tag);
		size = ft_size_int(stat->value);
		i = 0;
		while (i < 40 - size - 1)
		{
			if (i == 40 - size - 2)
				str[i] = ' ';
			else
				str[i] = '.';
			i++;
		}	
		ft_itoa_noalloc(&str[40 - size - 1], stat->value);
		mlx_string_put(game->mlx.display, game->mlx.window,
			(WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) + 20 + 200,
			(WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) + y, 0xDDDDDD, str);
	}
	return (0);
}

int	display_stat(t_game *game, t_player *player, double n)
{
	const t_tagint	*all_stats[] = {
		&player->stats.level, &player->stats.kill,
		&player->stats.time, &player->stats.use_object,
		&player->stats.door_open, &player->stats.life_loss};
	unsigned int	i;

	i = 0;
	while (i < (unsigned int)(sizeof(all_stats) / sizeof(all_stats[0]) * n))
	{
		display_one_stat(game, all_stats[i], 70 + (15 * MENU_HEIGHT / 100) + i * END_STAT_MARGE + game->end_menu.scroll_amount);
		i++;
	}
	return (0);
}

int	display_score(t_game *game, t_player *player)
{
	char			str[32];
	int				size;
	unsigned long	i;

	ft_itoa_noalloc(str, player->stats.score.value);
	size = 0;
	i = 0;
	my_mlx_put_image_to_window(game,
		&game->all_img.score, (WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) + 20,
		(WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) + 10);
	while (i < ft_strlen(str))
	{
		size -= game->all_img.all_number_img[str[ft_strlen(str) - i - 1] - '0'].width;
		my_mlx_put_image_to_window(game,
			&game->all_img.all_number_img[str[ft_strlen(str) - i - 1] - '0'],
			(WIN_WIDTH / 2 - ENDMENU_WIDTH / 2) + 20 + 450 + size,
			(WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2) + 34);
		i++;
	}
	return (0);
}

int	endmenu_display(t_game *game)
{
	double	n;

	if (game->is_display == 0)
		return (0);
	my_mlx_put_image_to_window(
		game, &game->all_img.end_img,
		WIN_WIDTH / 2 - ENDMENU_WIDTH / 2,
		WIN_HEIGHT / 2 - ENDMENU_HEIGHT / 2);
	display_score(game, &game->player);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	n = (double)(game->last_frame - game->load_start_frame) / END_ANIMATION_DURATION;
	if (n > 1)
		n = 1;
	display_stat(game, &game->player, n);
	display_text(game, game->end_menu.all_objects);
	game->is_display = 0;
	return (0);
}
