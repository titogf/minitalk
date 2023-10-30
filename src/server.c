/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:57:16 by gfernand          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:44 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_SIGINFO;
	write(1, "PID: ", 5);
	ft_itoa(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}

void	handler(int sig)
{
	static int	bit = 0;
	static int	i = 0;
	static char	s[8];
	int			n;

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