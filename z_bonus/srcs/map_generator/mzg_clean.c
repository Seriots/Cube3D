/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:35:51 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 14:27:37 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	no_alone(char **map, int x, int y)
{
	int	k;

	k = 0;
	if (map[y][x + 1] == '+' || map[y][x + 1] == '/')
		k++;
	if (map[y][x - 1] == '+' || map[y][x - 1] == '/')
		k++;
	if (map[y + 1][x] == '+' || map[y + 1][x] == '/')
		k++;
	if (map[y - 1][x] == '+' || map[y - 1][x] == '/')
		k++;
	if (k == 0)
		return (1);
	return (0);
}

int	no_diago(char **map, int x, int y)
{
	int	k;

	k = 0;
	if (map[y][x + 1] == '1' || map[y][x + 1] == '2')
		k++;
	if (map[y][x - 1] == '1' || map[y][x - 1] == '2')
		k++;
	if (map[y + 1][x] == '1' || map[y + 1][x] == '2')
		k++;
	if (map[y - 1][x] == '1' || map[y - 1][x] == '2')
		k++;
	if (k == 0)
		return (1);
	return (0);
}

int	clean_diago(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (++j < height - 1)
	{
		i = 0;
		while (++i < width - 1)
		{
			if (map[j][i] == '1' && no_diago(map, i, j))
				map[j][i] = '2';
		}
	}
	j = 0;
	while (++j < height - 1)
	{
		i = 0;
		while (++i < width - 1)
		{
			if (map[j][i] == '2')
				map[j][i] = '0';
		}
	}
	return (0);
}

int	clean_alone(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (++j < height - 1)
	{
		i = 0;
		while (++i < width - 1)
		{
			if (map[j][i] == '+' && no_alone(map, i, j))
				map[j][i] = '0';
		}
	}
	return (0);
}

int	clean_maze(char **map, int width, int height)
{
	clean_alone(map, width, height);
	return (0);
}
