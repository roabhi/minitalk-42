/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:09:05 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/04 21:39:47 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <sys/signal.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

void	decoder(int sig, siginfo_t *info,  void *context)
{
	(void)info;
	(void)context;

	static int	counter = 0;
	static char	ch = 0;

	if (sig == SIGUSR2)
		ch = ch | 128 >> counter;
	counter++;
	//ft_printf("%d", counter);
	if (counter == 8)
	{
		if (ch == '\0')
			ft_putchar_cnt('\n');
		else
		{
			write(1, &ch, 1);
			ch = 0;
			counter = 0;
		}
	
	}

	//if (sig == SIGUSR1)
	//	ft_putchar_cnt('0');
	//else
	//	ft_putchar_cnt('1');
	//kill(info->si_pid, SIGUSR2);
	//if (!context)
	//return;
}

int	main(void)
{
	//ft_printf("El pid del server es %d", getpid());
	
	struct sigaction 	sa1;
	struct sigaction 	sa2;
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
	//signal(SIGUSR1, decoder);
	//signal(SIGUSR2, decoder);
	while (1)
		sleep(5);
	return (0);
}
