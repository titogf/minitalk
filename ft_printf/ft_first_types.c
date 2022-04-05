/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:57:42 by gfernand          #+#    #+#             */
/*   Updated: 2022/03/22 18:00:39 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	ft_type_c(char str)
{
	write(1, &str, 1);
	return (1);
}

int	ft_type_s(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int	ft_type_di(int n)
{
	char	*s;
	int		longi;
	int		i;

	longi = ft_cantidad(n);
	if (n == -2147483648)
		return (11);
	s = malloc(sizeof(char) * (longi + 1));
	if (n < 0)
	{
		s[0] = '-';
		n = n * (-1);
	}
	i = longi - 1;
	while (n >= 10)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	s[i] = (n % 10) + 48;
	s[longi] = '\0';
	i = ft_type_s(s);
	free(s);
	return (i);
}
