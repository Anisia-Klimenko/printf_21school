/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunb_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:00:59 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 17:01:00 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*s;
	int		i;
	int		len;

	len = ft_numlen(n);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	i = -1;
	if (n == 0)
		s[0] = '0';
	while (n > 0)
	{
		s[len - (++i) - 1] = (char)(n % 10 + 48);
		n = n / 10;
	}
	s[len] = '\0';
	return (s);
}

void	ft_putunb_fd(unsigned int n, int fd)
{
	char	*s;

	if (fd > 0)
	{
		s = ft_uitoa(n);
		ft_putstr_fd(s, fd);
		free(s);
	}
}
