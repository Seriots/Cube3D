/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_gameover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:13:12 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 20:42:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_loop.h"
#include "c3d_settings.h"
#include "c3d_init.h"
#include "c3d_utils.h"

#include "mlx.h"

int	gameover_text_update(t_game *game)
{
	double	n;

	n = (game->last_frame - game->load_start_frame) / END_GAMEOVER_DURATION;
	if (n > 1)
		load_endscreen(game);
	return (0);
}

int	gameover_display(t_game *game)
{
	mlx_put_image_to_window(game->mlx.display,
		game->mlx.window,
		game->all_img.screen_img.img, 0, 0);
	mlx_mouse_move(game->mlx.display, game->mlx.window,
		WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}

int	gameover_update(t_game *game)
{
	double	n;
	int		i;
	int		j;

	n = (game->last_frame - game->load_start_frame) / END_FADE_DURATION;
	if (n > 1)
		n = 1;
	j = -1;
	while (++j < (int)(WIN_HEIGHT * n))
	{
		i = -1;
		while (++i < WIN_WIDTH)
			my_mlx_pixel_put(&game->all_img.screen_img, i, j, 0x111111);
	}
	if (n == 1)
	{
		my_mlx_put_image_to_window(game, &game->all_img.game_over,
			WIN_WIDTH / 2 - game->all_img.game_over.width / 2,
			WIN_HEIGHT / 2 - game->all_img.game_over.height / 2);
		gameover_display(game);
		game->load_start_frame = game->last_frame;
		game->fcts.update_fct = gameover_text_update;
	}
	return (0);
}

int	load_gameover(t_game *game)
{
	game->fcts.keypressed_fct = 0;
	game->fcts.keyreleased_fct = 0;
	game->fcts.mousepressed_fct = 0;
	game->fcts.mousereleased_fct = 0;
	game->fcts.mousemove_fct = 0;
	game->fcts.update_fct = gameover_update;
	game->fcts.display_fct = gameover_display;
	game->load_start_frame = game->last_frame;
	game->player.stats.score.value += game->player.stats.kill.value * 50;
	game->player.stats.score.value += game->player.stats.use_object.value * 20;
	game->player.stats.score.value += game->player.stats.time.value * 10;
	return (0);
}
