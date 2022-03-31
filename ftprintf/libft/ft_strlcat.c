/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:05:46 by rabril-h          #+#    #+#             */
/*   Updated: 2022/01/14 19:29:39 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	size_d;
	size_t	size_s;
	size_t	i;

	size_d = 0;
	size_s = 0;
	i = 0;
	while (src[size_s] != '\0')
		size_s++;
	if (dstsize == 0)
		return (size_s);
	while (dst[size_d] != '\0')
		size_d++;
	if (dstsize <= size_d)
		return (dstsize + size_s);
	while (dstsize && (--dstsize - size_d) && src[i] != '\0')
	{
		dst[size_d + i] = src[i];
		i++;
	}
	dst[size_d + i] = '\0';
	return (size_s + size_d);
}
