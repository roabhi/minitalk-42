/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:11:11 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/11 21:20:12 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putunbr_cnt(unsigned int n, int l)
{
	if (n >= 10)
	{
		l += ft_putunbr_cnt(n / 10, l);
		l += ft_putchar_cnt(48 + (n % 10));
	}
	if (n < 10)
	{
		l += ft_putchar_cnt(n + '0');
	}
	return (l);
}
