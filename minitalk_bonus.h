/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:42:54 by gfernand          #+#    #+#             */
/*   Updated: 2023/11/01 12:45:04 by gfernand         ###   ########.fr       */
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
int		ft_itoa(int n);
int		ft_count(int n);
void	ft_caracter(int bit, int pid);
void	send_bit(int pid, char *message);

#endif
