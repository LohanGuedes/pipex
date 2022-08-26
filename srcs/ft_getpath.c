/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:15:34 by lguedes           #+#    #+#             */
/*   Updated: 2022/08/25 09:26:06 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/src/libft.h"
#include "pipex.h"
#include <unistd.h>

char	*build_path(char *path, char *cmd)
{
	char	*final_path;

	final_path = ft_calloc((int)(ft_strlen(path) + ft_strlen(cmd) + 1), 1);
	ft_strlcat(final_path, path, (ft_strlen(path) + 1));
	final_path[ft_strlen(path)] = '/';
	ft_strlcat(final_path, cmd, ft_strlen(path) + ft_strlen(cmd) + 2);
	return (final_path);
}

char	*ft_getpath(char *cmd, char **env)
{
	int		index;
	char	*path;
	char	**paths;
	char	*final_path;

	if (!access(&cmd[0], X_OK & F_OK))
		return (&cmd[0]);
	while (ft_strncmp(*env, "PATH=", 5))
		env++;
	path = *env;
	paths = ft_split(path + 5, ':');
	index = 0;
	while (paths[index])
	{
		final_path = build_path(paths[index], cmd);
		if (access(final_path, F_OK & X_OK) == 0)
		{
			return (final_path);
		}
		free(final_path);
		index++;
	}
	return (NULL);
}
