/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_default_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:42:48 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/06 14:16:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct_bonus.h"
#include "c3d_loop_bonus.h"

int	default_update(t_game *game)
{
	update_player(game);
	update_minimap(game);
	return (0);
}
