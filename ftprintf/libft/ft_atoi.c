/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:50:29 by rabril-h          #+#    #+#             */
/*   Updated: 2022/01/17 18:40:06 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int						c;
	unsigned long long int	res;
	int						sign;

	c = 0;
	res = 0;
	sign = 1;
	while (str[c] == 32 || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			sign = -1;
		c++;
	}
	while (str[c] != '\0' && (str[c] >= '0' && str[c] <= '9'))
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	if (res >= 9223372036854775807 && sign == -1)
		return (0);
	else if (res >= 9223372036854775807)
		return (-1);
	return ((int)(res * sign));
}
