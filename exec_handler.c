/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:11:32 by lguedes           #+#    #+#             */
/*   Updated: 2022/07/15 20:43:24 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/src/libft.h"
#include "pipex.h"

int g_FDNUM = 1;

int	ft_exec_handler(char **cmd, char *infile, int fd[2], int stdfno)
{

	extern char	**environ;
	
	dup2(fd[g_FDNUM], stdfno);
	close(fd[0]);
	close(fd[1]);
	g_FDNUM--;
	execve(ft_getpath(cmd[0], environ), cmd, NULL);
	return (0);
}
