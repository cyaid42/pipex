/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:36:37 by msan              #+#    #+#             */
/*   Updated: 2023/11/17 17:19:23 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*base;

	base = malloc(sizeof(t_list));
	if (!base)
		return (NULL);
	base->content = content;
	base->next = NULL;
	return (base);
}
