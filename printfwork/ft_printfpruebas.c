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

int	ft_printu(unsigned int n)
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

int ft_formatspec(char y, int a, char b, char *c)
{
	if (y == 'i' || y == 'd')
		return (ft_printnbr(a));
	else if (y == 'c')
		return (write (1, &b, 1), 1);
	else if (y == 's')
		return (ft_printstr(c));
	else
		return (0);
}

int	ft_printf(char *s, int a, char b, char *c)
{
	int	i;
	int len;

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
			len += ft_formatspec(s[i + 1], a, b, c);
			i++;
		}
		i++;
	}
	return (len);
}



int	main(void)
{
	int x;
	int a;
	int	b;

	x = -568899;
	a = printf("%% hola   %d %c %s\n", x, 'w', "yoyas");
	b = ft_printf("%% hola   %d %c %s\n", x, 'w', "yoyas");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
