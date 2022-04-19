/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:58:02 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/19 14:10:56 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_return_arg(const char *str, va_list lst);
int		ft_type_di(int n);
int		ft_cantidad(int n);
int		ft_type_s(char *str);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);

#endif
