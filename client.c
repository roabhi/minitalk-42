/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:02:43 by rabril-h          #+#    #+#             */
/*   Updated: 2022/04/01 21:17:16 by rabril-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decoder(unsigned char ch)
{
	int				c;
	unsigned int	base;

	ft_printf("El caracter vale %d \n", ch);
	c = 7;
	base = 128;
	while (c >= 0)
	{
		if (ch < base)
			ft_printf("imprime 0 \n");
		else
		{
			ft_printf("imprime 1 \n");	
			ch = ch - base;
		}
		base = base / 2;
		c--;
	}
}

int	main(int args, char **argv)
{
	int		_args;
	char	*params;
	int		counter;

	_args = args;
	params = *argv;
	counter = 0;
	if (args == 3)
	{
		//ft_printf("El numero de argumentos es %d, el PID del servidor es %s y el string a transmitir es %s\n\n", _args, argv[1], argv[2]);		
		while (argv[2][counter])
		{
			decoder(argv[2][counter]);
			ft_putchar_cnt('\n');
			counter++;
		}
	}	
	return (0);
}
