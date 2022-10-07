/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:35:51 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/07 18:12:00 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	random_mode(char **map, int x, int y)
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
}*/
/*
int	maze_mode(char **map, int x, int y)
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
}*/
/*
int	no_alone_inverted(char **map, int x, int y)
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
}*/

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

int	no_empty_corner(char **map, int x, int y)
{
	int	k;
	int	ver;

	k = 0;
	ver = 0;
	if (map[y][x + 1] == '1' && ++ver)
		k++;
	if (map[y][x - 1] == '1' && ++ver)
		k++;
	if (map[y + 1][x] == '1' && ++ver)
		k++;
	if (map[y - 1][x] == '1' && ++ver)
		k++;
	if (map[y - 1][x + 1] == '1')
		k++;
	if (map[y - 1][x - 1] == '1')
		k++;
	if (map[y + 1][x + 1] == '1')
		k++;
	if (map[y + 1][x - 1] == '1')
		k++;
	if (k > 1 && k == ver)
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
	//clean_diago(map, width, height);
	//clean_corner(map, width, height);
	clean_alone(map, width, height);
	return (0);
}
