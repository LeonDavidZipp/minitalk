/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:49:52 by lzipp             #+#    #+#             */
/*   Updated: 2023/10/15 08:29:44 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(const char c)
{
	int	worked;

	worked = write(1, &c, 1);
	if (worked == -1)
		return (-1);
	return (1);
}

int	ft_putstr_int(const char *s)
{
	int	len;
	int	worked;

	len = 0;
	while (s[len])
	{
		worked = write(1, &s[len], 1);
		if (worked == -1)
			return (-1);
		len++;
	}
	return (len);
}
