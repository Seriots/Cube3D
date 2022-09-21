/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:11:55 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/21 13:16:01 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

int	start_game(t_game *game)
{
	int	error;
	
	error = init_game(game);
	if (error)
		return (error);
	error = init_mlx(game);
	if (error)
		return (error);
}