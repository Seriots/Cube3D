/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgiband <lgiband@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:57:28 by rgarrigo          #+#    #+#             */
/*   Updated: 2022/10/08 16:35:24 by lgiband          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size_int(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		size++;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	ft_size_long(unsigned long n)
{
	int	size;

	size = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_positive;
	int		i;

	is_positive = (n >= 0);
	i = ft_size_int(n);
	str = malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		if (is_positive)
			str[i] = '0' + n % 10;
		else
			str[i] = '0' - n % 10;
		n /= 10;
	}
	if (!is_positive)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_noalloc(char dst[32], int n)
{
	int		is_positive;
	int		i;

	is_positive = (n >= 0);
	i = ft_size_int(n);
	if (i > 31)
		return (0);
	dst[i] = '\0';
	while (--i >= 0)
	{
		if (is_positive)
			dst[i] = '0' + n % 10;
		else
			dst[i] = '0' - n % 10;
		n /= 10;
	}
	if (!is_positive)
		dst[0] = '-';
	return (dst);
}

char	*ft_itoal_noalloc(char dst[32], unsigned long n)
{
	int		i;

	i = ft_size_long(n);
	if (i > 31)
		return (0);
	dst[i] = '\0';
	while (--i >= 0)
	{
		dst[i] = '0' + n % 10;
		n /= 10;
	}
	return (dst);
}

