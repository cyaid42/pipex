/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:39:33 by msan              #+#    #+#             */
/*   Updated: 2023/11/13 15:34:16 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)s;
	while (n)
	{
		s2[i] = '\0';
		i++;
		n--;
	}
}
