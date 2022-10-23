/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_score_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:49:56 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/21 11:33:49 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"

#include "mlx.h"

int	set_string(char *str, int i, t_scorev *score)
{
	int	size;

	ft_itoa_noalloc(str, i);
	ft_strlcat(str, ". ", 40);
	ft_strlcat(str, score->name, 40);
	size = ft_strlen(str);
	while (size < 40 - ft_size_int(score->score))
	{
		ft_strlcat(str, " ", 40);
		size++;
	}
	ft_itoa_noalloc(str + size, score->score);
	return (0);
}

int	display_ranking(t_game *game, t_score *score)
{
	int		i;
	char	str[40];
	
	i = 0;
	while (75 + i * SCORE_MARGE + game->score_menu.scroll_amount < 60)
		i++;
	while (i < score->size)
	{
		if (75 + i * SCORE_MARGE + game->score_menu.scroll_amount > 600)
			break ;
		set_string(str, i + 1, &score->score[i]);
		mlx_string_put(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2 - SCOREMENU_WIDTH / 2 + 20,
		75 + i * SCORE_MARGE + game->score_menu.scroll_amount, 
		0xDDDDDD, str);
		i++;
	}
	return (0);
}

int	score_display(t_game *game)
{
	my_mlx_put_image_to_window(game, &game->all_img.return_arrow,
	20 + (80 - game->all_img.return_arrow.width) / 2, 
	20 + (80 - game->all_img.return_arrow.height) / 2);
	mlx_put_image_to_window(game->mlx.display, game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	display_ranking(game, get_score_array(game));
	display_text(game, game->score_menu.all_objects);
	return (0);
}
