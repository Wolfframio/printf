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

int	main(void)
{
	int x;
	int a;

	x = 0;
	a = ft_printnbr(x);
	printf("\n%d", a);
}
