/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_init_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:10:34 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/24 18:06:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_menu.h"

int	init_menu(t_game *game)
{
	int	error;

	error = init_settings_menu(game);
	if (error)
		return (error);
	error = init_settings_menu2(game);
	if (error)
		return (error);
	error = init_start_menu(game);
	if (error)
		return (error);
	error = init_end_menu(game);
	if (error)
		return (error);
	error = init_score_menu(game);
	if (error)
		return (error);
	return (0);
}
