#ifndef PIPEX_H
# define PIPEX_H

// # include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

int	check_params(int argc, char const *argv[]);
char	*join(const char* s1, const char* s2);
char	*format_cmd(char *cmd);

#endif
