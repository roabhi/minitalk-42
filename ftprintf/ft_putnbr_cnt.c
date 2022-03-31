/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:16:26 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/11 20:30:39 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_n(int nb, int l)
{
	if (nb >= 10)
	{
		l += ft_putnbr_n(nb / 10, l);
		l += ft_putchar_cnt(48 + (nb % 10));
	}
	if (nb < 10)
	{
		l += ft_putchar_cnt(nb + '0');
	}
	return (l);
}

int	ft_putnbr_cnt(int n)
{
	int	l;
	int	is_negative;

	l = 0;
	is_negative = 0;
	if (n == -2147483648)
		return (ft_putstr_cnt("-2147483648"));
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar_cnt('-');
			is_negative = 1;
		}
		l += ft_putnbr_n(n, l);
	}
	if (is_negative)
		l++;
	return (l);
}
