/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:57:16 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/19 12:10:57 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	write(1, "PID: ", 5);
	ft_itoa(getpid());
	return (0);
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
	write(1, "\n", 1);
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
