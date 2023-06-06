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

int suma (int count, ...)
{
	va_list	args;
	va_start(args, count);
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (i < count)
	{
		sum = sum + va_arg(args, int);
		i++;
	}
	va_end(args);
	printf("%i\n", sum);
	return (sum);
}

int	main(void)
{
	suma(4, 1, 1, 1, 1);
	return (0);
}
