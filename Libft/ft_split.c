/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 03:01:41 by msan              #+#    #+#             */
/*   Updated: 2024/06/18 16:29:01 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_count_string(const char *s, char c)
{
	int		string;
	int		i;
	char	**tab;

	i = 0;
	string = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			string++;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (string + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

void	ft_count_letter(const char *s, char c, char **tab)
{
	int	i;
	int	string;
	int	letter;

	i = 0;
	string = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
			letter++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[string] = malloc(sizeof(char) * (letter + 1));
			if (!tab)
			{
				while (tab[string])
					free(tab[string--]);
			}
			string++;
			letter = 0;
		}
		i++;
	}
}

void	ft_fill_tab(char const *s, char c, char **tab)
{
	int	i;
	int	string;
	int	letter;

	i = 0;
	string = 0;
	letter = 0;
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			tab[string][letter] = s[i];
			letter++;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[string][letter] = '\0';
			string++;
			letter = 0;
		}
		i++;
	}
	tab[string] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (0);
	tab = ft_count_string(s, c);
	if (!tab)
		return (NULL);
	ft_count_letter(s, c, tab);
	ft_fill_tab(s, c, tab);
	return (tab);
}
