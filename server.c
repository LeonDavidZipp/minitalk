/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:20:15 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/30 13:34:35 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_char(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	(void)info;
	// ft_printf("Received signal %d from process %d\n", signal, info->si_pid);
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 32)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	act.sa_sigaction = receive_char;
	act.sa_flags = SA_SIGINFO;
	
	// while (1)
	// {
	// 	signal(SIGUSR1, receive_char);
	// 	signal(SIGUSR2, receive_char);
	// 	pause();
	// }
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
	return (0);
}
