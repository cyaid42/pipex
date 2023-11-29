/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msan <msan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:09:25 by msan              #+#    #+#             */
/*   Updated: 2023/11/11 03:09:27 by msan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_count(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n < 0)
		i--;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		j;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = digit_count(n) - 1;
	j = digit_count(n);
	res = malloc(sizeof(char) * (digit_count(n) + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	res[i] = (n % 10) + '0';
	res[j] = '\0';
	return (res);
}
