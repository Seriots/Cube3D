/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mzg_fillmap_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:52:31 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 11:52:50 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ver_ok(char **map, int x, int y)
{
	if (x == 0)
		return (1);
	if (map[y][x - 1] == 33)
		return (0);
	if (!map[y][x + 1])
		return (1);
	if (map[y][x + 1] == 33)
		return (0);
	return (1);
}

int	is_hor_ok(char **map, int x, int y)
{
	if (map[y - 1][x] == 33)
		return (0);
	if (!map[y + 1])
		return (1);
	if (map[y + 1][x] == 33)
		return (0);
	return (1);
}
