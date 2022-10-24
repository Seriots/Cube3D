/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_scores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:54:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 18:35:22 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"

#include "ft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	swap_score(t_scorev *score_a, t_scorev *score_b)
{
	t_scorev	tmp;

	ft_strlcpy(tmp.name, score_a->name, 20);
	tmp.score = score_a->score;
	ft_strlcpy(score_a->name, score_b->name, 20);
	score_a->score = score_b->score;
	ft_strlcpy(score_b->name, tmp.name, 20);
	score_b->score = tmp.score;
	return (0);
}

int	sort_scores(t_score *score)
{
	int	i;

	i = score->size - 1;
	while (i > 0)
	{
		if (score->score[i].score > score->score[i - 1].score)
		{
			swap_score(&score->score[i], &score->score[i - 1]);
			i = score->size - 1;
		}
		i--;
	}
	return (0);
}

int	add_new_scores(t_score *score, char *key, int value)
{
	if (score->size >= 200)
	{
		if (value > score->score[199].score)
		{
			ft_strlcpy(score->score[199].name, key, 20);
			score->score[199].score = value;
		}
	}
	else
	{
		ft_strlcpy(score->score[score->size].name, key, 20);
		score->score[score->size].score = value;
		score->size++;
	}
	return (0);
}

int	add_scores(t_game *game, t_score *score, char *key, int value)
{
	int	i;

	(void)game;
	i = 0;
	while (i < score->size)
	{
		if (ft_strcmp(score->score[i].name, key) == 0)
		{
			if (value > score->score[i].score)
				score->score[i].score = value;
			return (0);
		}
		i++;
	}
	add_new_scores(score, key, value);
	return (0);
}

int	init_scores(t_game *game, t_score *score, char *file)
{
	int		fd;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line, 0))
	{
		split = ft_split(line, '=');
		if (!split)
			return (free(line), close(fd), 10);
		if (ft_arraylen(split) == 2)
			add_scores(game, score, split[0], ft_atoi(split[1]));
		ft_free_tab(split);
		free(line);
	}
	sort_scores(score);
	close(fd);
	return (0);
}
