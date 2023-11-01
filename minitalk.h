/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:02 by gfernand          #+#    #+#             */
/*   Updated: 2023/11/01 12:44:51 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_H
# define MINITALK_H

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
