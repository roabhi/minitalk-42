/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:29:12 by rabril-h          #+#    #+#             */
/*   Updated: 2022/01/14 19:28:08 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*x;
	size_t	j;

	x = (char *)b;
	j = 0;
	while (j < len)
	{
		x[j] = c;
		j++;
	}
	return (b);
}
