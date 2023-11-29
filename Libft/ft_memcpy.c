/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:42:33 by msan              #+#    #+#             */
/*   Updated: 2023/11/17 17:37:08 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	int		i;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	while (n)
	{
		dest2[i] = src2[i];
		i++;
		n--;
	}
	return (dest);
}
