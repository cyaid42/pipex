/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:03:53 by cyaid             #+#    #+#             */
/*   Updated: 2024/06/20 05:30:50 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*istrue(t_data *data, char *s1)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < data->count)
	{
		tmp = s1;
		tmp = ft_strjoin("/", tmp);
		tmp = ft_strjoin_free_s2(data->tokens[i], tmp);
		if (access(tmp, F_OK) == 0)
		{
			free(s1);
			return (tmp);
		}
		i++;
		free(tmp);
	}
	free(s1);
	write(1, "Nann\n", 6);
	return (NULL);
}

int	get_path(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH=", 5) == 0)
		{
			path = data->env[i] + 5;
			break ;
		}
		++i;
	}
	if (path)
	{
		data->tokens = ft_split(path, ':');
		if (!data->tokens)
			return (1);
	}
	i = 0;
	while (data->tokens[i++])
		data->count++;
	return (0);
}

int	recup_split(char *s1, char *s2, t_data *data)
{
	if (!s1 || !*s1 || !s2 || !*s2)
	{
		free_tab(data->tokens);
		exit (1);
	}
	data->cmd1 = ft_split(s1, ' ');
	data->cmd2 = ft_split(s2, ' ');
	if (s1[0] == '/')
		return (0);
	else
		data->cmd1[0] = istrue(data, data->cmd1[0]);
	if (s2[0] == '/')
		return (0);
	else
		data->cmd2[0] = istrue(data, data->cmd2[0]);
	if (!data->cmd1 || !*data->cmd1 || !data->cmd2 || !*data->cmd2)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	static t_data	data = {0};
	char			*tmp1;

	if (env[0] == NULL)
		return (-1);
	if (argc == 5)
	{
		data.env = env;
		if (get_path(&data))
			return (write(1, "Error\n", 6),free_exit(&data) , 1);
		if (recup_split(argv[2], argv[3], &data))
			return (write(1, "Error\n", 6), free_exit(&data), 1);
		pipex(&data, argv);
	}
	else
		printf("Nombre d'arguments incorrect\n");
	return (0);
}
