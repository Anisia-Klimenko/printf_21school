/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acristin <acristin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:24:16 by acristin          #+#    #+#             */
/*   Updated: 2021/11/09 15:52:01 by acristin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		g_len;

int		ft_printf(const char *str, ...);

// SRC
void	ft_putptr_fd(void *p, int fd);
char	*ft_parse_str(const char *str, va_list args);
void	ft_init_flags(void);
void	ft_putunb_fd(unsigned int n, int fd);
void	ft_putxnb_fd(unsigned int n, int fd, char scale);
char	*ft_parse_flags(char *str);
char	*ft_find_width(char *tmp);
void	ft_process_flags(void);

// LIBFT
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);

#endif
