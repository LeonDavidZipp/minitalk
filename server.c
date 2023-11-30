/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:20:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/30 11:57:56 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_chars(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pid = getpid();
	ft_printf("%c", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, receive_chars);
		signal(SIGUSR2, receive_chars);
		pause();
	}
	return (0);
}
