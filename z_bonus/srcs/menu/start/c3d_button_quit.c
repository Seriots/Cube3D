/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_button_quit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:07:58 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/25 13:03:40 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "c3d_struct.h"
#include "c3d_event.h"
#include "c3d_settings.h"

#include "ft.h"
#include "dict.h"

int	quit_event(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		close_window(game);
	return (0);
}

t_dict	*init_quit_button(t_game *game)
{
	t_dict		*dict;
	t_button	*box;

	(void)game;
	box = malloc(sizeof(t_button));
	if (!box)
		return (0);
	box->box.height = 100;
	box->box.width = 300;
	box->box.x = WIN_WIDTH / 2 - box->box.width / 2;
	box->box.y = 1.8 * (WIN_HEIGHT / 3 - box->box.height / 2) + 70;
	ft_strlcpy(box->box.description, "Quit Game", 10);
	box->box.y_text = box->box.y + box->box.height / 2 + 10 / 2;
	box->box.x_text = box->box.x + box->box.width / 2
		- (FONT_WIDTH * ft_strlen(box->box.description) / 2);
	ft_strlcpy(box->box.font, FONT, ft_strlen(FONT));
	box->box.mouse_press = NULL;
	box->box.mouse_release = quit_event;
	dict = dict_new(BUTTON2, box);
	if (!dict)
		return (free(box), (void *)0);
	return (dict);
}
