/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_letter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:17:46 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/03 12:35:47 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "X11/keysym.h"

char	get_char(KeySym key, t_game *game)
{
	if (key == 65505 || key == 65507)
	{
		game->shift = 1;
		return (0);
	}
	else if (key > 127)
		return (0);
	else if (key >= 'a' && key <= 'z')
	{
		if (game->shift == 1)
			return (key - 32);
	}
	return (key);
}



