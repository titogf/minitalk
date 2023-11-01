/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:57:16 by gfernand          #+#    #+#             */
/*   Updated: 2023/11/01 12:56:57 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(void)
{
	struct sigaction	sa;

	write(1, "PID: ", 5);
	ft_itoa(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}

void	handler(int sig, siginfo_t *info, void *nothing)
{
	int	pid;

	pid = info->si_pid;
	if (sig == SIGUSR1)
		ft_caracter(0, pid);
	else if (sig == SIGUSR2)
		ft_caracter(1, pid);
	(void) nothing;
}

void	ft_caracter(int bit, int pid)
{
	static unsigned int	c = 0;
	static int			n_bits = 0;

	if (pid <= 0)
		return ;
	c *= 2;
	if (bit == 1)
		c += 1;
	n_bits++;
	if (n_bits >= 8)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			ft_putstr("WRONG\n");
			exit(0);
		}
		n_bits = 0;
		c = 0;
	}
	kill(pid, SIGUSR2);
}
