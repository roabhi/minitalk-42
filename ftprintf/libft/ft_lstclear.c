/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:25:32 by rabril-h          #+#    #+#             */
/*   Updated: 2022/02/08 15:31:07 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	void	*aux;

	if (*lst)
	{
		while (*lst)
		{
			element = *lst;
			aux = element->next;
			*lst = aux;
			del(element->content);
			free(element);
		}
		*lst = NULL;
	}
}
