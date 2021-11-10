/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:24:29 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 10:50:30 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(unsigned long int n)
{
	int					len;
	unsigned long int	pow;

	len = 1;
	pow = 1;
	while (n / 16 >= pow)
	{
		pow *= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa16(unsigned long int nb)
{
	char	*str;
	char	*base;
	int		len;
	int		i;

	base = "0123456789abcdef";
	len = ft_numlen(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[len - i - 1] = base[nb % 16];
		nb = nb / 16;
		i++;
	}
	str[len] = '\0';
	return (str);
}

void	ft_putptr_fd(void *p, int fd)
{
	char	*s;

	if (fd > 0)
	{
		s = ft_itoa16((unsigned long int)p);
		write(1, "0x", 2);
		g_len += 2;
		ft_putstr_fd(s, 1);
		free(s);
	}
}
