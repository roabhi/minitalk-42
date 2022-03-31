/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthnbr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:35:03 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/11 23:11:10 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthchar_forbase(unsigned int x, char *base, int b, int count)
{
	if (x >= b)
	{
		count += ft_puthchar_forbase(x / b, base, b, count);
		write(1, &base[x % b], 1);
	}
	else if (x < b)
		ft_putchar_cnt(base[x]);
	count++;
	return (count);
}

int	ft_puthnbr_base(unsigned int nbr, char *base)
{
	int	my_int_base;
	int	c;

	c = 0;
	if (ft_strlen(base) > 1 && base != (void *)0)
	{
		my_int_base = (int)ft_strlen(base);
		c += ft_puthchar_forbase(nbr, base, my_int_base, c);
	}
	return (c);
}

int	ft_puthnbr_cnt(unsigned int n, char c)
{
	int	l;

	l = 0;
	if (c == 'h')
		l += ft_puthnbr_base(n, "0123456789abcdef");
	else
		l += ft_puthnbr_base(n, "0123456789ABCDEF");
	return (l);
}
