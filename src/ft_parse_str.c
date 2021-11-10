/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:19:59 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 15:23:14 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_parse_str(const char *str, va_list args)
{
	char	*tmp;

	tmp = (char *)str + 1;
	if (*tmp == 'd' || *tmp == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*tmp == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*tmp == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*tmp == 'p')
		ft_putptr_fd(va_arg(args, void *), 1);
	else if (*tmp == 'u')
		ft_putunb_fd(va_arg(args, unsigned int), 1);
	else if (*tmp == 'x')
		ft_putxnb_fd(va_arg(args, unsigned int), 1, 'x');
	else if (*tmp == 'X')
		ft_putxnb_fd(va_arg(args, unsigned int), 1, 'X');
	else if (*tmp == '%')
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (tmp);
}
