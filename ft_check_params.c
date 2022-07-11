#include "pipex.h"

int	check_params(int argc, char const *argv[])
{
	if (access(argv[1], F_OK | R_OK | W_OK) == -1)
	{
		perror("Pipex - Error");
		exit(1);
	}
	if (argc != 5)
	{
		write(2, "Pipex - Error: Wrong number of arguments.\n", 42);
		exit(1);
	}
	return (0);
}
