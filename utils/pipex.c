/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:19:15 by cyaid             #+#    #+#             */
/*   Updated: 2024/06/20 05:15:41 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_exit(t_data *data)
{
	free_tab(data->tokens);
	free_tab(data->cmd1);
	free_tab(data->cmd2);
}

void	enfant1(t_data *data)
{
	dup2(data->file1, STDIN_FILENO);
	close(data->file1);
	close(data->pipefd[0]);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[1]);
	execve(data->cmd1[0], data->cmd1, data->env);
}

void	enfant2(t_data *data)
{
	close(data->pipefd[1]);
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	dup2(data->file2, STDOUT_FILENO);
	close(data->file2);
	execve(data->cmd2[0], data->cmd2, data->env);
}

int	pipex(t_data *data, char **argv)
{
	int	child1;
	int	child2;

	pipe(data->pipefd);
	child1 = fork();
	if (!child1)
	{
		data->file1 = open(argv[1], O_RDONLY);
		if (data->file1 == -1)
			return (1);
		enfant1(data);
	}
	child2 = fork();
	if (!child2)
	{
		data->file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
		enfant2(data);
	}
	wait(NULL);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
	free_exit(data);
	return (0);
}
