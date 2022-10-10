/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_menu_utils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:40:39 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/10 15:51:54 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_init.h"

#include "ft.h"
#include "mlx.h"

void	load_path(t_game *game, t_textinput *textinput, char **path)
{
	t_img_data	img_data;
	char		*new_path;
	int			error;

	error = init_xpm_image(game, &img_data, textinput->path);
	if (error)
	{
		game->menu.error = error;
		ft_strlcpy(textinput->path, *path, 256);
		textinput->size = ft_strlen(*path);
		return ;
	}
	new_path = ft_calloc(sizeof(char), ft_strlen(textinput->path) + 1);
	if (!new_path)
	{
		game->menu.error = 10;
		ft_strlcpy(textinput->path, *path, 256);
		textinput->size = ft_strlen(*path);
		return ;
	}
	ft_strlcpy(new_path, textinput->path, ft_strlen(textinput->path) + 1);
	free(*path);
	*path = new_path;
	mlx_destroy_image(game->mlx.display, (*textinput->modified_value).img);
	*textinput->modified_value = img_data;
}

char	get_char_from_key(KeySym key, int shift, int caps)
{
	const char	base[10] = "7486293150";

	if (key >= 65429 && key <= 65438)
		return (base[key - 65429]);
	if (key < 32 || key > 126)
		return (0);
	if ((shift && caps) || (!shift && !caps))
		return (key);
	else
		return (key - 32);
}

void	reset_seed(t_seed *seed)
{
	seed->is_selected = 0;
	seed->tmp_value = *seed->modified_value;
}

void	set_error_value(t_menu *menu, int code)
{
	menu->error = code;
}
