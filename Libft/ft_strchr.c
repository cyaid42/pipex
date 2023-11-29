/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:56:59 by msan              #+#    #+#             */
/*   Updated: 2023/11/17 17:42:34 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (&s1[i]);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
		i++;
	}
	return (0);
}
