/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:19:19 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/06 17:50:14 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	int		_args;
	char	*params;
	int		counter;
	int		server_pid;

	_args = args;
	params = *argv;
	counter = 0;
	if (args == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][counter])
		{
			decoder(argv[2][counter], server_pid);
			ft_putchar_cnt('\n');
			counter++;
		}
		decoder('\n', server_pid);
	}	
	return (0);
}
