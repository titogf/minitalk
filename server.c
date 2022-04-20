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
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = SA_SIGINFO;
	write(1, "PID: ", 5);
	ft_itoa(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

void	handler(int sig)
{
	static int	c;
	static int	bit;

	bit = 0;
	if (sig == SIGUSR1)
		c |= 128 >> bit;
	else
		c ^= 128 >> bit;
}
