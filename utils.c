/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 11:31:18 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/25 17:05:48 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				i;
	int				sig;

	i = 0;
	result = 0;
	if (str[0] == '-')
	{
		sig = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - 48) + (result * 10);
		i++;
	}
	return (result * sig);
}

int	ft_itoa(int n)
{
	char	*s;
	int		longi;
	int		i;

	longi = ft_count(n);
	s = malloc(sizeof(char) * (longi + 1));
	if (!s)
		return (0);
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
	write(1, s, longi);
	free(s);
	return (0);
}

int	ft_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0 && power == 0)
		return (1);
	if (nb == 0)
		return (0);
	while (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (0);
}
