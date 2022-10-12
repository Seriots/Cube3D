/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_save_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:50:35 by lgiband           #+#    #+#             */
/*   Updated: 2022/10/12 21:51:05 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	sf(void *ptr, char *value)
{
	*(float *)ptr = (float)ft_atoi(value);
	return (0);
}

int	si(void *ptr, char *value)
{
	*(int *)ptr = ft_atoi(value);
	return (0);
}

int	ss(void *ptr, char *value)
{
	ft_strlcpy((char *)ptr, value, 256);
	return (0);
}
