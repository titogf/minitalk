/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:56:27 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/25 15:32:10 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

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
	pid = ft_atoi(argv[1]);
	convert_bits(pid, argv[2]);
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
