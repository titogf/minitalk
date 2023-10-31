/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:58:25 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/25 17:25:53 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	convert_bits(int pid, char *str);
void	handler(int sig, siginfo_t *info, void *nothing);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_count(int n);
int		ft_itoa(int n);
int		ft_caracter(char *str);
int		ft_recursive_power(int nb, int power);
void	readed(int sig);

#endif
