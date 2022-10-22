/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_scores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:54:59 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/22 19:01:38 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_save.h"

#include "ft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int	save_scores(t_game *game, t_score *score, char *file)
{
	int		fd;
	int		i;
	int		j;

	i = 0;
	(void)game;
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	while (i < score->size)
	{
		j = 0;
		while (j < score->size)
		{
			if (score->score[j].pos == i + 1)
			{
				if (ft_strlen(score->score[j].name) > 0)
					save_int(fd, score->score[j].name, score->score[j].score);
				else
					save_int(fd, "Default", score->score[j].score);
				break ;
			}
			j++;
		}
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
			score->score[i].score, score->score[i].pos);
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

int	sort_scores(t_score *score, int new, int value, int pre_value)
{
	int	score_pos;
	int	i;

	score_pos = 0;
	i = 0;
	while (i < score->size)
	{
		if (i != new && score->score[i].score >= value)
			score_pos++;
		else if (i != new && score->score[i].score <= value
			&& score->score[i].score > pre_value)
			score->score[i].pos += 1;
		i++;
	}
	score->score[new].pos = score_pos + 1;
	return (0);
}

int	add_scores(t_game *game, t_score *score, char *key, int value)
{
	int	i;
	int	tmp;

	(void)game;
	i = 0;
	while (i < score->size)
	{
		if (ft_strcmp(score->score[i].name, key) == 0)
		{
			if (value > score->score[i].score)
			{
				tmp = score->score[i].score;
				score->score[i].score = value;
				sort_scores(score, i, value, tmp);
			}
			print_scores(score);
			return (0);
		}
		i++;
	}
	if (score->size >= 200)
	{
		if (value > score->score[199].score)
		{
			ft_strlcpy(score->score[199].name, key, 20);
			score->score[i].score = value;
			sort_scores(score, 199, value, 0);
		}
	}
	else
	{
		ft_strlcpy(score->score[score->size].name, key, 20);
		score->score[score->size].score = value;
		sort_scores(score, score->size, value, 0);
		score->size++;
	}
	return (0);
}

int	init_scores(t_game *game, t_score *score, char *file)
{
	int		fd;
	char 	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		split = ft_split(line, '=');
		if (!split)
			return (free(line), close(fd), 10);
		if (ft_arraylen(split) == 2)
			add_scores(game, score, split[0], ft_atoi(split[1]));
		ft_free_tab(split);
		free(line);
	}
	close(fd);
	return (0);
}

