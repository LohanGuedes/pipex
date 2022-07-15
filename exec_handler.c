#include "pipex.h"

int g_FDNUM  = 0;

int	ft_exec_handler(char **cmd, char *ifile, int fd[2], int stdfno)
{

	extern char	**environ;
	dup2(fd[g_FDNUM], stdfno);
	close(fd[0]);
	close(fd[1]);
	g_FDNUM++;
	execve(ft_getpath(cmd[0], environ), cmd, environ);
	return (0);
}
