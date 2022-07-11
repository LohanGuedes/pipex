/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:13:37 by lguedes           #+#    #+#             */
/*   Updated: 2022/07/09 22:17:48 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	int		fd[2];
	int pid1;
	int pid2;
	char	*const newenv[] = { NULL };
	char	**newargv;

	newargv = (char **)malloc(sizeof(char*) * 3);
	check_params(argc, argv);
	if(pipe(fd) == -1)
	{
		perror("Pipex - Error");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Pipex - Error");
		exit(2);
	}
	if (pid1 == 0)
	{
		newargv = (char *[3]) { (char *)argv[2], (char *)argv[1], NULL };
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//                 /usr/bin/cat
		execve(format_cmd((char *)argv[2]), newargv, newenv);
	}
	waitpid(pid1, NULL, 0);
	if (pid1 != 0)
	{
		pid2 = fork();
	}
	if(pid2 != 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (pid2 == 0)
	{
		newargv = (char *[3]) { (char *)argv[3], NULL, NULL };
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//                 /usr/bin/wc
		execve(format_cmd((char *)argv[3]), newargv, newenv);
	}
	waitpid(pid2, NULL, 0);
	free(newargv);
	return 0;
}
