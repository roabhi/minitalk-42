/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:09:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/06 19:31:26 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decoder(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;
	static char	ch = 0;

	(void)info;
	(void)context;
	if (sig == SIGUSR2)
		ch = ch | 128 >> counter;
	counter++;
	if (counter == 8)
	{
		write(1, &ch, 1);
		ch = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;
	pid_t				my_pid;

	my_pid = getpid();
	ft_printf("Server PID is %d", (int)my_pid);
	ft_putchar_cnt('\n');
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = decoder;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = decoder;
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		sleep(5);
	return (0);
}
