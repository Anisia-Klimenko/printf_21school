/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:24:20 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 15:17:26 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		args;
	char		*tmp;

	g_len = 0;
	tmp = (char *)str;
	va_start(args, str);
	while (*tmp)
	{
		if (*tmp == '%')
			tmp = ft_parse_str(tmp, args);
		else
			ft_putchar_fd(*tmp, 1);
		tmp++;
	}
	va_end(args);
	return (g_len);
}
