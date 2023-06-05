/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:26:31 by imontero          #+#    #+#             */
/*   Updated: 2023/06/05 13:27:26 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_formatspec(char y, va_list args)
{
	if (y == 'i' || y == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (y == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (y == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (y == 'u')
		return (ft_printnbru(va_arg(args, unsigned int)));
	else
		return (0);
}

int ft_printf(const char *s, ...)
{
	va_list	args;
	int	i;
	int len;

	va_start(args, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			len++;
		}
		if (s[i] == '%' && s[i + 1] == '%')
		{
			write(1, "%", 1);
			len++;
			i++;
		}
		if (s[i] == '%' && ft_strchr("cspdiuxX", s[i + 1]) != NULL)
		{
			len += ft_formatspec(s[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
