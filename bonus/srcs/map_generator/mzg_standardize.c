/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_standardize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:33:21 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/09 13:13:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	standardize_maze(char **map, int width, int height)
{
	int	i;
	int	j;

	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[j][i] == 33)
				map[j][i] = '1';
			else if (map[j][i] != 32)
				map[j][i] = '0';
			i++;
		}
		j++;
	}
	return (0);
}
