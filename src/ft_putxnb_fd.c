/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnb_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:24:34 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 10:52:54 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int				len;
	unsigned int	pow;

	len = 1;
	pow = 1;
	while (n / 16 >= pow)
	{
		pow *= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoa16(unsigned int nb)
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

void	ft_putxnb_fd(unsigned int n, int fd, char scale)
{
	char	*s;
	int		i;

	s = ft_itoa16(n);
	if (scale == 'X')
	{
		i = 0;
		while (s[i] != '\0')
		{
			s[i] = ft_toupper(s[i]);
			i++;
		}
	}
	ft_putstr_fd(s, fd);
	free(s);
}
