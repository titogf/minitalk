/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:34:35 by gfernand          #+#    #+#             */
/*   Updated: 2022/03/22 14:40:35 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_long(unsigned int n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_cantidad(int n)
{
	int	contador;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
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

int	ft_longp(unsigned long int n)
{
	int	i;

	if (n == 0)
	{
		write(1, "0x0", 3);
		return (0);
	}
	i = 3;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i);
}
