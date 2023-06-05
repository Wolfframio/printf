/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebasprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 09:50:44 by imontero          #+#    #+#             */
/*   Updated: 2023/06/05 11:21:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int	ft_printf(const *char format, ...)
{
	va_list	args;
	va_start(args, format);
	
}


int	main(void)
{
	int x;
	int a;
	int	b;

	x = -5699;
	a = printf("%%hola%d%c%s\n", x, 'w', "yoyas");
	b = ft_printf("%%hola%d%c%s\n", x, 'w', "yoyas");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
