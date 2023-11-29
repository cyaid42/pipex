/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:11:24 by msan              #+#    #+#             */
/*   Updated: 2023/11/13 15:37:17 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*(little) == 0)
		return ((char *)(big));
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((big[i + j]) && (big[i + j] == little[j]) && (i + j < len))
		{
			j++;
		}
		if (little[j] == 0)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
