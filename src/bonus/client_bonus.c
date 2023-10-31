/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:39:15 by gfernand          #+#    #+#             */
/*   Updated: 2023/10/30 16:08:17 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk_bonus.h"

int	received_signal(int sig);

int	main(int argc, char **argv)
{
	int	i;
	int	server_pid;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_putstr("WRONG PARAMETERS\n");
		exit(1);
	}
	while (argv[1][i])
	{
		if (!((argv[1][i] >= 48 && argv[1][i] <= 57) || argv[1][0] == '-'))
		{
			ft_putstr("WRONG PID\n");
			exit(1);
		}
		i++;
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, (void *)received_signal);
	convert_bits(server_pid, argv[2]);
}

void	convert_bits(int pid, char *str)
{
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((str[i] & (128 >> bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(1000);
		}
		i++;
	}
}

int	received_signal(int sig)
{
	static int	count = 0;

	if (sig == SIGUSR1)
		count++;
	return (count);
}
