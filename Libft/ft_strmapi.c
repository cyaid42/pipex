/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:10:51 by msan              #+#    #+#             */
/*   Updated: 2023/11/13 14:58:45 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*cpy;

	if (!s)
	{
		return (ft_strdup(""));
	}
	cpy = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!cpy)
	{
		return (0);
	}
	i = 0;
	j = 0;
	while (s[i])
	{
		cpy[j] = (*f)(i, s[i]);
		i++;
		j++;
	}
	cpy[j] = '\0';
	return (cpy);
}
