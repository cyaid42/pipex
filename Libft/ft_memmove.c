/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msan <msan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:35:22 by msan              #+#    #+#             */
/*   Updated: 2023/11/10 15:45:51 by msan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	dest2 = (char *)dest;
	src2 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	if (dest2 > src2)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	else
	{
		i = 0;
		while (n > 0)
		{
			dest2[i] = src2[i];
			i++;
			n--;
		}
	}
	return (dest);
}
