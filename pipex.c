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
#include <unistd.h>

int	main(int argc, char const *argv[])
{
	// First, check if the number of args are = 4
	if (argc != 4)
	{

		write(2, "Wrong number of arguments.\n", 27);
		return 1;
	}
	return 0;
}
