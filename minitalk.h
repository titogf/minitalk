/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:02 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/21 12:48:31 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	convert_bits(int PID, char *str);
void	handler(int sig);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_count(int n);
int		ft_itoa(int n);
int		ft_caracter(char *str);
int		ft_recursive_power(int nb, int power);

#endif
