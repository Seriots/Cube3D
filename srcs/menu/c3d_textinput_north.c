/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_textinput_north.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:25:01 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/04 15:59:34 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_settings.h"
#include "c3d_menu.h"
#include "c3d_loop.h"
#include "c3d_utils.h"
#include "c3d_init.h"

#include "ft.h"
#include "mlx.h"

#include <stdio.h>

void	load_path(t_game *game, t_textinput *textinput, char **path)
{
	t_img_data	img_data;
	char		*new_path;
	int			error;

	error = init_xpm_image(game, &img_data, textinput->path);
	if (error)
	{
		ft_strlcpy(textinput->path, *path, 256);
		textinput->size = ft_strlen(*path);
	}
	else
	{
		new_path = ft_calloc(sizeof(char), ft_strlen(textinput->path) + 1);
		if (!new_path)
		{
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
}

char	get_char_from_key(KeySym key, int shift, int caps)
{
	if (key < 32 || key > 126)
		return (0);
	if ((shift && caps) || (!shift && !caps))
		return (key);
	else
		return (key - 32);
}

int	north_keypress(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects, 6)->value;
	if ((key == XK_Delete || key == XK_KP_Delete || key == 65288) && textinput->size > 0)
	{
		textinput->size -= 1;
		textinput->path[textinput->size] = '\0';
	}
	else if (key == XK_Return || key == XK_KP_Enter)
	{
		load_path(game, textinput, textinput->modified_path);
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		textinput->is_selected = 0;
		textinput->start_display = 0;
		mlx_do_key_autorepeatoff(game->mlx.display);
	}
	else if (key == XK_Shift_L || key == XK_Shift_R)
		textinput->shift += 1;
	else if (key == XK_Caps_Lock && textinput->caps_lock == 0)
		textinput->caps_lock = 2;
	else if (textinput->size < 255)
	{
		if (get_char_from_key(key, textinput->shift, textinput->caps_lock) != '\0')
		{
			textinput->path[textinput->size] = get_char_from_key(key, textinput->shift, textinput->caps_lock);
			textinput->size += 1;
			textinput->start_display += 1;
			textinput->path[textinput->size] = '\0';
		}
	}
	return (0);
}

int	north_keyrelease(KeySym key, t_game *game)
{
	t_textinput	*textinput;

	textinput = dict_getelem_number(game->menu.all_objects, 6)->value;
	if (key == XK_Escape)
	{
		ft_strlcpy(textinput->path, *textinput->modified_path, 256);
		textinput->size = ft_strlen(textinput->path);
		game->fcts.keypressed_fct = menu_key_press;
		game->fcts.keyreleased_fct = menu_key_release;
		textinput->is_selected = 0;
		textinput->start_display = 0;
		mlx_do_key_autorepeatoff(game->mlx.display);
	}
	else if (key == XK_Shift_L || key == XK_Shift_R)
	{
		if (textinput->shift > 0)
			textinput->shift -= 1;
	}
	else if (key == XK_Caps_Lock && textinput->caps_lock != 0)
		textinput->caps_lock -= 1;
	return (0);
}

int	north_release(int button, int x, int y, t_game *game)
{
	t_textinput	*textinput;

	if (button == 1)
	{
		textinput = dict_getelem_number(game->menu.all_objects, 6)->value;
		if (x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) >= textinput->box.x
			&& x - (WIN_WIDTH / 2 - MENU_WIDTH / 2) <= textinput->box.x + textinput->box.width
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) >= textinput->box.y + game->menu.scroll_amount
			&& y - (WIN_HEIGHT / 2 - MENU_HEIGHT / 2) <= textinput->box.y + game->menu.scroll_amount + textinput->box.height)
		{
			textinput->is_selected = !textinput->is_selected;
			if (textinput->is_selected)
			{
				textinput->start_display = textinput->size;
				game->fcts.keypressed_fct = north_keypress;
				game->fcts.keyreleased_fct = north_keyrelease;
				mlx_do_key_autorepeaton(game->mlx.display);
				clear_all_other_selected(game, textinput);
			}
			else
			{
				ft_strlcpy(textinput->path, *textinput->modified_path, 256);
				textinput->size = ft_strlen(textinput->path);
				game->fcts.keypressed_fct = menu_key_press;
				game->fcts.keyreleased_fct = menu_key_release;
				textinput->is_selected = 0;
				textinput->start_display = 0;
				mlx_do_key_autorepeatoff(game->mlx.display);
			}
		}
		game->fcts.mousereleased_fct = menu_mouse_release;
	}
	return (0);
}

int	north_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		game->fcts.mousereleased_fct = north_release;
	return (0);
}

t_dict	*init_textinput_north(t_game *game)
{
	t_textinput	*textinput;
	t_dict		*obj;

	(void)game;
	textinput = malloc(sizeof(t_textinput));
	if (!textinput)
		return (0);
	textinput->box.height = 24;
	textinput->box.width = 200;
	textinput->box.x = 100;
	textinput->box.y = 250;
	textinput->box.x_text = textinput->box.x - 80;
	textinput->box.y_text = textinput->box.y + 15;
	textinput->is_selected = 0;
	textinput->shift = 0;
	textinput->caps_lock = 0;
	ft_strlcpy(textinput->box.description, "North path", 11);
	ft_strlcpy(textinput->box.font, "-sony-*-*-*-*-*-*-230-*-*-*-*-iso8859-*", 40);
	textinput->box.mouse_press = north_press;
	textinput->box.mouse_release = NULL;
	textinput->modified_value = &game->all_img.no;
	textinput->modified_path = &game->map.no;
	ft_strlcpy(textinput->path, *textinput->modified_path, 256);
	textinput->size = ft_strlen(textinput->path);
	textinput->max_size = 256;
	textinput->max_char_display = (textinput->box.width / 6) - 1;
	textinput->start_display = 0;
	obj = dict_new(TEXTINPUT, textinput);
	if (!obj)
		return (free(textinput), (void *)0);
	return (obj);
}
