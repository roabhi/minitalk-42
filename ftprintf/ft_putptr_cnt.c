/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:59:53 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/11 23:05:14 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar_forbase(unsigned long long x, char *base, int b, int count)
{
	if (x >= b)
	{
		count += ft_putchar_forbase(x / b, base, b, count);
		write(1, &base[x % b], 1);
	}
	else if (x < b)
		ft_putchar_cnt(base[x]);
	count++;
	return (count);
}

int	ft_putptr_base(unsigned long long nbr, char *base)
{
	int	my_int_base;
	int	c;

	c = 0;
	if (ft_strlen(base) > 1 && base != (void *)0)
	{
		my_int_base = (int)ft_strlen(base);
		c += ft_putchar_forbase(nbr, base, my_int_base, c);
	}
	return (c);
}

int	ft_putptr_cnt(unsigned long int n)
{
	int	l;

	l = 0;
	if (!n)
	{
		l = ft_putstr_cnt("0x0");
		return (l);
	}
	else
	{
		l += ft_putstr_cnt("0x");
		l += ft_putptr_base(n, "0123456789abcdef");
	}
	return (l);
}
