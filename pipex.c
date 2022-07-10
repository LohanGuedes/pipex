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

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *join(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result) // thanks @pmg
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

int	check_params(int argc, char const *argv[])
{
	if (access(argv[1], F_OK | R_OK | W_OK) == -1)
	{
		perror("Error");
		exit(1);
	}

	if (argc != 5)
	{
		write(2, "Wrong number of arguments.\n", 27);
		exit(1); // TODO how to check the status
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	/*
	 * I hecking love C <3
	 *  */
	char	*const newenv[] = { NULL };
	char	*const newargv[] = { (char *)argv[2], (char *)argv[1], NULL };
	char	*const command_path = "/usr/bin/";
	char	*final_command = (char *)malloc(strlen(command_path) + strlen(argv[2]));

	final_command = join(command_path, argv[2]);

	check_params(argc, argv);
	execve(final_command, newargv, newenv);
	return 0;
}

/*
** char *const *env[] {'infile=test.txt\0', 'cmd1=cat\0', 'cmd2=wc -l', 'outfile=foo'}
*/
