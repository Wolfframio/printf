/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bformat: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:15:37 bformat imontero          #+#    #+#             */
/*   Updated: 2023/06/04 12:15:37 bformat imontero         ###   ########.fr       */
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
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int ft_printpointer(char *addr)
{
	int	len;

	if (addr == NULL)
		return (write(1, "0x0", 3));
	len = ft_printstr("0x");
	len += ft_printhex((unsigned long long int)addr, 'p');
	return (len);
}

int	ft_printhex(unsigned long long int nbr, char format)
{
	char	*base;
	int		len;
	
	len = 0;
	if (format == 'x' || format == 'p')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		len += ft_printhex(nbr / 16, format);
		len += ft_printhex(nbr % 16, format);
	}
	else
	{
		len += write(1, &base[nbr], 1);
	}
	return (len);	
}

int ft_formatspec(char format, va_list args)
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
		return (-1);
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

int	main(void)
{
	int x;
	int a;
	int	b;
	char	*str;

	str = "hola";
	x = -97248;
	a = printf("%i %p %c %s", 66, 44, 666, str, 'w', "yoyas");
	printf("\n-\n");
	b = ft_printf("%i", 666, str, 'w', "yoyas");
	printf("\n-\n");
	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}
