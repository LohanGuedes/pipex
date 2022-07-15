#include "pipex.h"

int	ft_check_params(int argc, char *const argv[])
{
	if (access(argv[1], F_OK | R_OK ) == -1)
	{
		perror("Pipex - Error");
		exit(2);
	}
	if (argc != 5)
	{
		write(2, "Pipex - Error: Wrong number of arguments.\n", 42);
		exit(22);
	}
	return (0);
}
