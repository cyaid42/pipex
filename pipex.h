/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:40:50 by cyaid             #+#    #+#             */
/*   Updated: 2024/06/20 04:56:16 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_stack_node
{
	char	**env;
	char	**tokens;
	char	**cmd1;
	char	**cmd2;
	int		count;
	int		pipefd[2];
	int		file1;
	int		file2;
}			t_data;

void		enfant1(t_data *data);
void		enfant2(t_data *data);
int			recup_split(char *s1, char *s2, t_data *data);
int			get_path(t_data *data);
char		*istrue(t_data *data, char *s1);
int			pipex(t_data *data, char **argv);
void		free_exit(t_data *data);
void		free_tab(char **tab);

// int	synthax(char *s1, t_data *data);

#endif