/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:06:53 by rabril-h          #+#    #+#             */
/*   Updated: 2022/01/14 19:41:47 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (s1[c] == s2[c] && s1[c] && s2[c] && c < n - 1)
		c++;
	return ((unsigned char)s1[c] - (unsigned char)s2[c]);
}
