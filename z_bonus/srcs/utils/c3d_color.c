/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:54:10 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/13 17:37:32 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"

unsigned int	get_color(int color_setting, unsigned int color)
{
	unsigned int	bw_color;
	int				r;
	int				g;
	int				b;

	if (color_setting)
		return (color);
	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	bw_color = (r + g + b) / 3;
	return ((bw_color << 16) | (bw_color << 8) | bw_color);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_put_image_to_window(t_game *game, t_img_data *data, int x, int y)
{
	char	*dst;
	int		i;
	int		j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			dst = data->addr + (j * data->line_length
					+ i * (data->bits_per_pixel / 8));
			if (*(unsigned int *)dst != 0xFF000000)
				my_mlx_pixel_put(&game->all_img.screen_img, x + i, y + j,
					*(unsigned int *)dst);
			i++;
		}
		j++;
	}
}
