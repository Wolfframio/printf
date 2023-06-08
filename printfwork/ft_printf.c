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

int	ft_formatspec(char format, va_list args)
{
	if (format == '%')
		return (ft_printchar('%'));
	else if (format == 'i' || format == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (format == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'u')
		return (ft_printnbru(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_printhex(va_arg(args, unsigned long long int), format));
	else if (format == 'p')
		return (ft_printpointer(va_arg(args, char *)));
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
	if (!s)
		return (0);
	while (s[i])
	{
		if (*(ft_strchr(s, '%') + 1) == ' ' || *(ft_strchr(s, '%') + 1) == '\0')
			return (-1);
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			len += ft_formatspec(s[i + 1], args);
			i++;
		}
		else
		{
			len += write(1, &s[i], 1);
		}
		i++;
	}
	va_end(args);
	return (len);
}
