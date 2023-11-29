/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msan <msan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:41:04 by msan              #+#    #+#             */
/*   Updated: 2023/11/28 23:20:05 by msan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "Libft/libft.h"


int	main(int argc, char **argv)
{
	int	fd[2];

	if (pipe(fd) == -1)
	{
		printf("Error while opening the pipe\n");
		return 1;
	}
	int	id = fork();
	
}
