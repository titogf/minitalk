/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:39:04 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/21 14:05:34 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_SIGINFO;
	write(1, "PID: ", 5);
	ft_itoa(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

void	handler(int sig)
{
	static int	bit;
	static int	i;
	static char	s[8];
	int			n;

	if (!i)
		i = 0;
	if (!bit)
		bit = 0;
	if (sig == SIGUSR1)
		s[i] = '1';
	else
		s[i] = '0';
	i++;
	bit++;
	if (bit == 8)
	{
		n = ft_caracter(s);
		write(1, &n, 1);

		bit = 0;
		i = 0;
	}
}

int	ft_caracter(char *str)
{
	int	i;
	int	bit;
	int	c;

	i = 0;
	bit = 7;
	c = 0;
	while (str[i])
	{
		if (str[i] == '1')
			c += ft_recursive_power(2, bit);
		i++;
		bit--;
	}
	return (c);
}
