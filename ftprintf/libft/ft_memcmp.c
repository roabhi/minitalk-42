/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:17:47 by rabril-h          #+#    #+#             */
/*   Updated: 2022/01/17 14:42:56 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;
	char	*st1;
	char	*st2;

	st1 = (char *)s1;
	st2 = (char *)s2;
	c = 0;
	while (c < n)
	{
		if (st1[c] != st2[c])
		{
			return ((unsigned char)st1[c] - (unsigned char)st2[c]);
		}
		c++;
	}
	return (0);
}
