/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:45:43 by leon              #+#    #+#             */
/*   Updated: 2023/11/30 12:13:22 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_putchar_int(const char c);

int		ft_putstr_int(char const *s);

int		ft_putnbr_int(int n, int len);

int		ft_putu_int(unsigned int n, int len);

int		ft_puthex_big_int(unsigned int n, int len);

int		ft_puthex_small_int(unsigned int n, int len);

int		ft_putpointer_int(unsigned long n, int len);

#endif
