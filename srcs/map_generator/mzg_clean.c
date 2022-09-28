/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:35:51 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/09 15:20:09 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int no_diago(char **map, int x, int y)
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

int no_empty_corner(char **map, int x, int y)
{
	int	k;
	int	hor;
	int	ver;

	k = 0;
	hor = 0;
	ver = 0;
	if (map[y][x + 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y][x - 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y + 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x + 1] == '1')
		k++;
	if (map[y - 1][x - 1] == '1')
		k++;
	if (map[y + 1][x + 1] == '1')
		k++;
	if (map[y + 1][x - 1] == '1')
		k++;
	if (k > 1 && k == hor + ver)
		return (1);
	return (0);
}

int random_mode(char **map, int x, int y)
{
	int	k;
	int	hor;
	int	ver;

	k = 0;
	hor = 0;
	ver = 0;
	if (map[y][x + 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y][x - 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y + 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x + 1] == '1')
		k++;
	if (map[y - 1][x - 1] == '1')
		k++;
	if (map[y + 1][x + 1] == '1')
		k++;
	if (map[y + 1][x - 1] == '1')
		k++;
	if (k == 2 && hor == 1 && ver == 1)
		return (1);
	if (k == 3 && hor == 2 && ver == 1)
		return (1);
	if (k == 3 && hor == 1 && ver == 2)
		return (1);
	if (k == 4 && hor == 2 && ver == 2)
		return (1);
	return (0);
}

int maze_mode(char **map, int x, int y)
{
	int	k;
	int	hor;
	int	ver;

	k = 0;
	hor = 0;
	ver = 0;
	if (map[y][x + 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y][x - 1] == '1')
	{
		k++;
		ver++;
	}
	if (map[y + 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x] == '1')
	{
		k++;
		hor++;
	}
	if (map[y - 1][x + 1] == '1')
		k++;
	if (map[y - 1][x - 1] == '1')
		k++;
	if (map[y + 1][x + 1] == '1')
		k++;
	if (map[y + 1][x - 1] == '1')
		k++;
	if (k == 0)
		return (1);
	if (k > 1 && k == hor + ver)
		return (1);
	return (0);
}

int no_alone_inverted(char **map, int x, int y)
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
	if (map[y - 1][x + 1] == '1' || map[y - 1][x + 1] == '2')
		k++;
	if (map[y - 1][x - 1] == '1' || map[y - 1][x - 1] == '2')
		k++;
	if (map[y + 1][x + 1] == '1' || map[y + 1][x + 1] == '2')
		k++;
	if (map[y + 1][x - 1] == '1' || map[y + 1][x - 1] == '2')
		k++;
	if (k >= 2)
		return (1);
	return (0);
}

int no_alone(char **map, int x, int y)
{
	int	k;

	k = 0;
	if (map[y][x + 1] == '1')
		k++;
	if (map[y][x - 1] == '1')
		k++;
	if (map[y + 1][x] == '1')
		k++;
	if (map[y - 1][x] == '1')
		k++;
	if (map[y - 1][x + 1] == '1')
		k++;
	if (map[y - 1][x - 1] == '1')
		k++;
	if (map[y + 1][x + 1] == '1')
		k++;
	if (map[y + 1][x - 1] == '1')
		k++;
	if (k <= 1)
		return (1);
	return (0);
}

int	clean_diago(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 1;
	while (j < height - 1)
	{
		i = 1;
		while (i < width - 1)
		{
			if (map[j][i] == '1' && no_diago(map, i, j))
				map[j][i] = '2';
			i++;
		}
		j++;
	}
	j = 1;
	while (j < height - 1)
	{
		i = 1;
		while (i < width - 1)
		{
			if (map[j][i] == '2')
				map[j][i] = '0';
			i++;
		}
		j++;
	}
	return (0);
}

int	clean_corner(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 1;
	while (j < height - 1)
	{
		i = 1;
		while (i < width - 1)
		{
			if (map[j][i] == '0' && no_empty_corner(map, i, j))
				map[j][i] = '2';
			i++;
		}
		j++;
	}
	j = 1;
	while (j < height - 1)
	{
		i = 1;
		while (i < width - 1)
		{
			if (map[j][i] == '2')
				map[j][i] = '1';
			i++;
		}
		j++;
	}
	return (0);
}

int	clean_maze(char **map, int width, int height)
{
	clean_diago(map, width, height);
	clean_corner(map, width, height);
	return (0);
}
