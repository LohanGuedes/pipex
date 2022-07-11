#include "pipex.h"

char	*format_cmd(char *cmd)
{
	char	*usrbin = "/usr/bin/";
	char	*final;

	final = (char *)malloc(strlen(usrbin) + strlen(cmd));
	final = join(usrbin, cmd);
	return(final);
}
