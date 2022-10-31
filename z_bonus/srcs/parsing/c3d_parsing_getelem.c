/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_parsing_getelem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:12:09 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/31 08:47:55 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_struct.h"
#include "c3d_utils.h"
#include "c3d_parsing.h"
#include "c3d_object.h"

#include "ft.h"

int	default_parse(t_game *game, char *tag, char *arg)
{
	char	**split;
	int		x;
	int		y;
	int		error;

	if (!arg)
		return (3);
	split = ft_split(arg, ',');
	if (!split)
		return (10);
	if (ft_arraylen(split) != 2)
		return (ft_free_tab(split), 3);
	if (is_only_set(split[0], "0123456789")
		&& is_only_set(split[1], "0123456789"))
	{
		x = ft_atoi(split[0]);
		y = ft_atoi(split[1]);
		error = init_obj(game, tag, x, y);
		return (ft_free_tab(split), error);
	}
	return (ft_free_tab(split), 3);
}

int	get_object(t_game *game, char **split)
{
	const t_objinit	all_template[][2] = {{{KEY, default_parse}},
	{{LAMP, default_parse}}, {{HEAL, default_parse}},
	{{FULLHEAL, default_parse}}, {{BONUSHP, default_parse}},
	{{ENERGY, default_parse}}, {{B_ENERGY, default_parse}},
	{{GHOST, default_parse}}, {{MAP, default_parse}},
	{{SYRINGE, default_parse}}};
	unsigned int	i;
	int				error;

	i = 0;
	while (i < sizeof(all_template) / sizeof(all_template[0]))
	{
		if (!ft_strcmp(split[0], all_template[i]->tag))
		{
			error = all_template[i]->fct(game, all_template[i]->tag, split[1]);
			return (ft_free_tab(split), error);
		}
		i++;
	}
	return (ft_free_tab(split), 2);
}

int	get_elem(t_game *game, t_map *map, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (10);
	if (ft_arraylen(split) != 2)
		return (ft_free_tab(split), 3);
	if (ft_strcmp(split[0], "NO") == 0 && !map->no)
		map->no = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "SO") == 0 && !map->so)
		map->so = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "WE") == 0 && !map->we)
		map->we = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "EA") == 0 && !map->ea)
		map->ea = ft_strdup(split[1]);
	else if (ft_strcmp(split[0], "F") == 0 && map->f == -1)
		map->f = ft_color(split[1]);
	else if (ft_strcmp(split[0], "C") == 0 && map->c == -1)
		map->c = ft_color(split[1]);
	else
		return (get_object(game, split));
	return (ft_free_tab(split), 0);
}
