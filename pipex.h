#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/src/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

int		ft_exec_handler(char **cmd, char *ifile, int fd[2], int stdfno);

int		ft_check_params(int argc, char *const argv[]);

char	*ft_getpath(char *cmd, char **env);

char	**ft_splitcmd(char *s, char c);

#endif
