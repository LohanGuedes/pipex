/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:13:37 by lguedes           #+#    #+#             */
/*   Updated: 2022/07/15 20:27:34 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/src/libft.h"
#include <unistd.h>


int	main(int argc, char *const argv[], char *const env[])
{
	int	fd[2];
	int	*pids;
	char	**split_cmds;

	ft_check_params(argc, argv);
	pids = (int *)malloc(sizeof(int) * 2);
	if(pipe(fd) == -1)
	{
		perror("Pipex - Error");
		exit(32);
	}

	pids[0] = fork();
	// Process 1 (for cmd 1)
	if (pids[0] < 0)
	{
		perror("Pipex - Error");
		exit(3);
	}
	if (pids[0] == 0)
	{
		ft_exec_handler(ft_split(argv[2], ' '), (char *)argv[1], fd, STDOUT_FILENO);
	}
		
	waitpid(pids[0], NULL, 0);
	
	if (pids[0] != 0)
		pids[1] = fork();
	if(pids[1] != 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (pids[1] == 0)
	{
		ft_exec_handler(ft_splitcmd(argv[3], ' '), NULL, fd, STDIN_FILENO);
	}
	waitpid(pids[1], NULL, 0);
	return (0);
}
