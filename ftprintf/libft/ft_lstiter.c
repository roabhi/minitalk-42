/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:02:42 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/08 15:27:41 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*element;

	if (lst)
	{
		while (lst)
		{
			element = lst;
			f(element->content);
			lst = lst->next;
		}
	}
}
