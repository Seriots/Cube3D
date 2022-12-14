/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:28:23 by lgiband           #+#    #+#             */
/*   Updated: 2022/09/30 11:02:56 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sign(float x)
{
	if (x < 0)
		return (-1);
	if (x > 0)
		return (1);
	return (0);
}

int	pure_sign(float x)
{
	if (x < 0)
		return (-1);
	return (1);
}

double	dabs(double nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
