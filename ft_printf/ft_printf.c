/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:58:02 by gfernand          #+#    #+#             */
/*   Updated: 2022/03/31 13:19:14 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		i;
	int		result;

	va_start(lst, str);
	i = -1;
	result = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				result += ft_return_arg(str + i, lst);
		}
		else
		{
			write(1, str + i, 1);
			result++;
		}
	}
	va_end(lst);
	return (result);
}

int	ft_return_arg(const char *str, va_list lst)
{
	void	*string;

	if (*str == '%')
		return (ft_type_c('%'));
	string = va_arg(lst, char *);
	if (!string && *str == 's')
		return (ft_type_null());
	if (*str == 'c')
		return (ft_type_c((char) string));
	if (*str == 's')
		return (ft_type_s((char *) string));
	if (*str == 'p')
		return (ft_type_p((unsigned long int) string));
	if (*str == 'd' || *str == 'i')
		return (ft_type_di((int) string));
	if (*str == 'u')
		return (ft_type_u((unsigned int) string));
	if (*str == 'x')
		return (ft_type_x((unsigned int) string));
	if (*str == 'X')
		return (ft_type_upperx((unsigned int) string));
	return (0);
}
