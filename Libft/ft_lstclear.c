/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 04:37:27 by msan              #+#    #+#             */
/*   Updated: 2023/11/17 18:23:51 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	list = *lst;
	while (list)
	{
		(*del)(list->content);
		tmp = list->next;
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
