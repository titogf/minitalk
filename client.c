/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:56:27 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/19 18:52:52 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	i;
	int	PID;

	i = 0;
	while (argv[1][i])
	{
		if (!(argv[1][i] >= 48 && argv[1][i] <= 57 || argv[1][0] == '-'))
		{
			ft_putstr("WRONG PID\n");
			exit(1);
		}
		i++;
	}
	if (argc != 3 || argv[2][0] == '\0')
	{
		ft_putstr("WRONG PARAMETERS\n");
		exit(1);
	}
	PID = ft_atoi(argv[1]);
	convert_bits(PID, argv[2]);
}

void	convert_bits(int PID, char *str)
{
	int	bit;
	int	i;

	i = 0;
	while (1)
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[i] & (128 >> bit) == 0)
				kill(PID, SIGUSR2);
			else
				kill(PID, SIGUSR1);
			bit++;
		}
		if (!str[i])
			break;
		i++;
	}
}
