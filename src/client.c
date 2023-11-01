/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:56:27 by gfernand          #+#    #+#             */
/*   Updated: 2023/11/01 12:43:57 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_putstr("WRONG PARAMETERS\n");
		exit(1);
	}
	send_bit(ft_atoi(argv[1]), argv[2]);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
		pause();
	}
}

void	handler(int sig, siginfo_t *info, void *nothing)
{
	static int	bit_count = 0;

	bit_count++;
	if (bit_count == 8)
		bit_count = 0;
	usleep(500);
	send_bit(-1, NULL);
	(void) sig;
	(void) info;
	(void) nothing;
}

void	send_bit(int pid, char *message)
{
	static int		server_pid;
	static char		*full_message;
	static int		next_c = 0;
	static int		next_bit = 0;
	unsigned int	send;

	if (pid != -1)
		server_pid = pid;
	if (message != NULL)
		full_message = message;
	if (full_message[next_c] == '\0')
		exit(0);
	send = (unsigned int) full_message[next_c];
	send = (send & (1 << (7 - next_bit))) >> (7 - next_bit);
	if (send % 2 == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
	if (++next_bit >= 8)
	{
		next_bit = 0;
		next_c++;
	}
}
