/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:18:06 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/30 11:57:02 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		return (1);
	}
	while (*argv[2])
	{
		send_char(ft_atoi(argv[1]), *argv[2]);
		argv[2]++;
	}
	return (0);
}
