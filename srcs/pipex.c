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
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int	exec_cmd1(int infile, int outfile, char **cmds[2], char **envp)
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(ft_getpath(cmds[0][0], (char **)envp), cmds[0], envp);
	perror("Pipex error - command not found: ");
	exit(22);
}

int	exec_cmd2(int infile, int outfile, char **cmds[2], char **envp)
{
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	execve(ft_getpath(cmds[1][0], (char **)envp), cmds[1], envp);
	perror("Pipex error - command not found: ");
	exit(22);
}

void	build_cmds(char **output[2], char *cmd1, char *cmd2)
{
	if (cmd1[0] == ' ')
		cmd1++;
	if (cmd2[0] == ' ')
		cmd2++;
	if (!*cmd1 || !*cmd2)
	{
		write(2, "No command passed to either cmd1 or cmd2 or both\n", 49);
		exit(37);
	}
	output[0] = ft_split(cmd1, ' ');
	output[1] = ft_split(cmd2, ' ');
}

void	open_in_n_out(int in_out[2], char *infilePath, char *outfilePath)
{
	in_out[0] = open(infilePath, O_RDONLY);
	in_out[1] = open(outfilePath, O_WRONLY | O_CREAT | O_TRUNC, 0664);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pids[2];
	int		read_n_write[2];
	int		files[2];
	char	**cmds[2];

	ft_check_params(argc, (char **)argv);
	build_cmds(cmds, (char *)argv[2], (char *)argv[3]);
	open_in_n_out(files, (char *)argv[1], (char *)argv[4]);
	pipe(read_n_write);
	pids[0] = fork();
	if (pids[0] == 0)
	{
		close(read_n_write[0]);
		exec_cmd1(files[0], read_n_write[1], cmds, (char **)envp);
	}
	if (pids[0] != 0)
		pids[1] = fork();
	if (pids[1] == 0)
	{
		close(read_n_write[1]);
		exec_cmd2(read_n_write[0], files[1], cmds, (char **)envp);
	}
	close(read_n_write[0]);
	close(read_n_write[1]);
	return (0);
}
