/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:15:37 by imontero          #+#    #+#             */
/*   Updated: 2023/06/04 12:15:37 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if (((char)c) == '\0')
		return (&((char *)s)[i]);
	return (NULL);
}

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printnbr(int n)
{
	int	b;
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-", 1);
		i += write(1, "2", 1);
		i += ft_printnbr(147483648);
	}
	else if (n < 0)
	{
		i += write(1, "-", 1);
		i += ft_printnbr(-n);
		n *= -1;
	}
	else if (n >= 10)
	{
		i += ft_printnbr(n / 10);
		i += ft_printnbr(n % 10);
	}
	else
	{
		b = n + 48;
		i += write(1, &b, 1);
	}
	return (i);
}

int	ft_printnbru(unsigned int n)
{
	int	b;
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_printnbr(n / 10);
		i += ft_printnbr(n % 10);
	}
	else
	{
		b = n + 48;
		i += write(1, &b, 1);
	}
	return (i);
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_formatspec(char y, va_list args)
{
	if (y == '%')
		return (ft_printchar('%'));
	else if (y == 'i' || y == 'd')
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
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			len += ft_formatspec(s[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (len);
}


int	main(void)
{
	unsigned int x;
	int a;
	int	b;

	x = 4294967295;
	a = printf("%% hola   %u %c %s\n", x, 'w', "yoyas");
	b = ft_printf("%% hola   %u %c %s\n", x, 'w', "yoyas");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
