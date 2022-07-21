/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:13:37 by lguedes           #+#    #+#             */
/*   Updated: 2022/07/19 21:53:08 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/src/libft.h"
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int	execcmd(int infile,  int pipe_end, char **cmds[2], char **envp)
{
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(pipe_end, STDOUT_FILENO);
		close(pipe_end);
		execve(ft_getpath(cmds[1][0], (char **)envp), cmds[1], envp);
		return(-1);
}

int main(int argc, char const *argv[], char *const envp[])
{
	int pids[2];
	int read_n_write[2]; // 0 - Read &  1 - Write
	int files[2];
	char **cmds[2];


	cmds[0] = ft_split(argv[2], ' ');
	cmds[1] = ft_split(argv[3], ' ');

	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[4], O_WRONLY);

	// Parent
	pipe(read_n_write);
	pids[0] = fork();

	// Child 1 (cmd1)
	if(pids[0] == 0){
		close(read_n_write[0]);
		execcmd(files[0], read_n_write[1], cmds, (char **)envp);

		// Why wasn't this working?
		/* dup2(files[0], STDIN_FILENO); */
		/* close(files[0]); */
		/* dup2(read_n_write[1], STDOUT_FILENO); */
		/* close(read_n_write[1]); */
		/* execve(ft_getpath(cmds[0][0], (char **)envp), cmds[0], envp); */
	}
	if (pids[0] != 0)
	{
		pids[1] = fork();
	}

	//Child 2 (cmd 2)
	if(pids[1] == 0)
	{
		close(read_n_write[1]);
		execcmd(read_n_write[0], files[1], cmds, (char **)envp);

		// Why wasn't this working?
		/* dup2(files[1], STDIN_FILENO); */
		/* close(files[1]); */
		/* dup2(read_n_write[0], STDOUT_FILENO); */
		/* close(read_n_write[0]); */
		/* execve(ft_getpath(cmds[1][0], (char **)envp), cmds[1], envp); */
	}

	close(read_n_write[0]);
	close(read_n_write[1]);
	return (0);
}

