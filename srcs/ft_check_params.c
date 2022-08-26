/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:15:41 by lguedes           #+#    #+#             */
/*   Updated: 2022/08/24 20:15:43 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_check_params(int argc, char *const argv[])
{
	if (access(argv[1], F_OK & R_OK) == -1)
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
