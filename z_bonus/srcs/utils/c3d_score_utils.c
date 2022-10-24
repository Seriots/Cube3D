/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_score_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:30:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 20:37:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"
#include "c3d_menu.h"

#include "ft.h"

#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int	save_scores(t_game *game, t_score *score, char *file)
{
	int		fd;
	int		i;

	i = 0;
	(void)game;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	while (i < score->size)
	{
		if (ft_strlen(score->score[i].name) > 0)
			save_int(fd, score->score[i].name, score->score[i].score);
		else
			save_int(fd, "Default", score->score[i].score);
		i++;
	}
	close(fd);
	return (0);
}

int	print_scores(t_score *score)
{
	int	i;

	i = 0;
	while (i < score->size)
	{
		printf("%s -> %d, pos: %d\n", score->score[i].name,
			score->score[i].score, i);
		i++;
	}
	return (0);
}

t_score	*get_score_array(t_game *game)
{
	if (game->settings.difficulty == 0)
		return (&game->settings.easy_score);
	else if (game->settings.difficulty == 1)
		return (&game->settings.medium_score);
	else
		return (&game->settings.hard_score);
}

char	*get_score_file(t_game *game)
{
	if (game->settings.difficulty == 0)
		return (EASY_FILE);
	else if (game->settings.difficulty == 1)
		return (MEDIUM_FILE);
	else
		return (HARD_FILE);
}

int	set_height_s(t_game *game, t_scrollbar *scrollbar, t_score *score)
{
	scrollbar->box.height = set_height_score(game,
			&scrollbar->max_obj, score->size);
	scrollbar->max = 594 - scrollbar->box.height;
	return (0);
}
