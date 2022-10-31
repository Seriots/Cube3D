/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:48:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:48:03 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_only_set(char *line, char *set)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (ft_isinset(line[i], set) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_iscolor(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) > 3 && ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(line) > 255)
		return (0);
	return (1);
}

int	ft_color(char *line)
{
	char	**split;
	int		color;

	split = ft_split(line, ',');
	if (!split)
		return (-1);
	if (ft_arraylen(split) != 3)
		return (ft_free_tab(split), -1);
	if (ft_iscolor(split[0]) == 0 || ft_iscolor(split[1]) == 0
		|| ft_iscolor(split[2]) == 0)
		return (ft_free_tab(split), -1);
	color = ft_atoi(split[0]) * 256 * 256
		+ ft_atoi(split[1]) * 256
		+ ft_atoi(split[2]);
	return (ft_free_tab(split), color);
}
