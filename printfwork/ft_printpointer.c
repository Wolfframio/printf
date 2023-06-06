/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:47:29 by imontero          #+#    #+#             */
/*   Updated: 2023/06/06 14:52:55 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long long int addr)
{
	int	len;

	len = ft_printstr("0x");
	len += ft_printhex(addr, 'p');
	return (len);
}
