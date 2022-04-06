/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:38 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/06 21:11:38 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reciever(int sig)
{
	if (sig == 31)
	{
		usleep(100);
		ft_printf("signal recivido, %d \n", (int)sig);
	}		
	else
	{
		ft_putstr_cnt("\nSe recibio todo el mensaje\n");
		exit(1);
	}
}

void	decoder(unsigned char ch, pid_t pid)
{
	int				c;
	unsigned int	base;

	c = 7;
	base = 128;
	while (c >= 0)
	{
		if (ch < base)
		{
			kill(pid, SIGUSR1);
		}			
		else
		{
			kill(pid, SIGUSR2);
			ch = ch - base;
		}
		base = base / 2;
		c--;
		usleep(100);
	}
}

int	main(int args, char **argv)
{
	int		counter;
	int		server_pid;

	counter = 0;
	if (args == 3)
	{
		signal(SIGUSR1, reciever);
		signal(SIGUSR2, reciever);
		server_pid = ft_atoi(argv[1]);
		ft_putchar_cnt('\n');
		while (argv[2][counter])
		{
			decoder(argv[2][counter], server_pid);
			ft_putchar_cnt('\n');
			counter++;
		}
		decoder('\0', server_pid);
	}
	pause();
	return (0);
}
