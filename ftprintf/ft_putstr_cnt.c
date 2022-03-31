/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 21:32:44 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/10 15:16:17 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr_cnt(const char *s)
{
	int	l;

	l = 0;
	if (!s)
	{
		l = write(1, "(null)", 6);
		return (l);
	}
	while (s[l])
		l += ft_putchar_cnt(s[l]);
	return (l);
}
