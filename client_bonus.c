/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:18:38 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/06 19:19:29 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reciever_1(int sig)
{
	ft_putstr_cnt("\nSe recibio el mensaje");
	(void)sig;
	exit(1);
}

void	reciever_2(int sig)
{
	(void)sig;
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
			ft_putchar_cnt('0');
			kill(pid, SIGUSR1);
		}			
		else
		{
			ft_putchar_cnt('1');
			kill(pid, SIGUSR2);
			ch = ch - base;
		}
		base = base / 2;
		c--;
		usleep(200);
	}
}

int	main(int args, char **argv)
{
	int		counter;
	int		server_pid;

	counter = 0;
	if (args == 3)
	{
		signal(SIGUSR1, reciever_1);
		signal(SIGUSR2, reciever_2);
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
