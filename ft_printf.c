/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:58:02 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/19 11:36:58 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		result;

	va_start(lst, str);
	i = -1;
	result = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				result += ft_return_arg(str + i, lst);
		}
		else
		{
			write(1, str + i, 1);
			result++;
		}
	}
	va_end(lst);
	return (result);
}

int	ft_return_arg(const char *str, va_list lst)
{
	void	*string;

	if (*str == '%')
		return (ft_type_c('%'));
	string = va_arg(lst, char *);
	if (*str == 'd' || *str == 'i')
		return (ft_type_di((int) string));
	return (0);
}

int	ft_type_di(int n)
{
	char	*s;
	int		longi;
	int		i;

	longi = ft_cantidad(n);
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

int	ft_cantidad(int n)
{
	int	contador;

	contador = 1;
	if (n < 0)
		contador++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		contador++;
	}
	return (contador);
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
