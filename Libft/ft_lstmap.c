/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:47:58 by msan              #+#    #+#             */
/*   Updated: 2023/11/13 14:55:31 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst && lst != NULL)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			while (list)
			{
				tmp = list->next;
				(*del)(list->content);
				free(list);
				list = tmp;
			}
			lst = NULL;
		}
		ft_lstadd_back(&list, tmp);
		lst = lst->next;
	}
	return (list);
}
