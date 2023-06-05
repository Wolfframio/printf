/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imontero <imontero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:08:38 by imontero          #+#    #+#             */
/*   Updated: 2023/06/04 17:08:38 by imontero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
int		ft_printnbr(int n);
int		ft_printnbru(unsigned int n);
int		ft_printstr(char *s);
int		ft_printchar(char c);

#endif