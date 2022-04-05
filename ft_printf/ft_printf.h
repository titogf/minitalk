/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:00:24 by gfernand          #+#    #+#             */
/*   Updated: 2022/04/04 15:00:59 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_return_arg(const char *str, va_list lst);
int	ft_type_null(void);
int	ft_type_c(char str);
int	ft_type_s(char *str);
int	ft_type_di(int n);
int	ft_cantidad(int n);
int	ft_type_u(unsigned int n);
int	ft_type_x(unsigned int n);
int	ft_type_upperx(unsigned int n);
int	ft_long(unsigned int n);
int	ft_type_p(unsigned long int n);
int	ft_longp(unsigned long int n);

#endif
