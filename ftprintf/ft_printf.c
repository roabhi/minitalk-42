/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:12:55 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/12 14:29:24 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"

int	ft_checkarg(char ch, va_list args)
{
	int		print_arg;

	print_arg = 0;
	if (ch == 'c')
		print_arg += ft_putchar_cnt(va_arg(args, int));
	else if (ch == 's')
		print_arg += ft_putstr_cnt(va_arg(args, char *));
	else if (ch == 'p')
		print_arg += ft_putptr_cnt(va_arg(args, unsigned long long));
	else if (ch == 'd' || ch == 'i')
		print_arg += ft_putnbr_cnt(va_arg(args, int));
	else if (ch == 'u')
		print_arg += ft_putunbr_cnt(va_arg(args, unsigned int), 0);
	else if (ch == 'x')
		print_arg += ft_puthnbr_cnt(va_arg(args, unsigned int), 'h');
	else if (ch == 'X')
		print_arg += ft_puthnbr_cnt(va_arg(args, unsigned int), 'H');
	else if (ch == '%')
		print_arg += ft_putchar_cnt(ch);
	return (print_arg);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			print;	

	if (!s)
		return (0);
	va_start (args, s);
	count = 0;
	print = 0;
	while (s[count])
	{
		if (s[count] == '%')
		{
			count++;
			print += ft_checkarg(s[count], args);
		}
		else
		{
			ft_putchar_fd(s[count], 1);
			print++;
		}
		count++;
	}
	va_end(args);
	return (print);
}
