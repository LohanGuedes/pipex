#include "pipex.h"
#include <string.h>

char*	build_path(char *path, char *cmd)
{
	char	*final_path;
	int	final_len;
	int	path_len;
	int	cmd_len;
;
	path_len = ft_strlen(path);
	cmd_len = (int)ft_strlen(cmd);
	final_len = (path_len + cmd_len) + 2;
	final_path = (char*)malloc(sizeof(char) * final_len);
	ft_strlcpy(final_path, path, final_len);
	final_path[path_len] = '/';
	ft_strlcat(final_path, cmd, final_len);
	return(final_path);
}

char	*ft_getpath(char *cmd, char **env)
{
	int		index;
	int		j;
	char	*path;
	char	**cmds;
	char	**paths;
	char	*final_path;

	index = 0;
	j = 0;
	while (env[index] != NULL)
	{
		if (!ft_strncmp(env[index], "PATH=", 5))
		{
			path = env[index];
			paths = ft_split(path+5, ':');
			while(paths[j])
			{
				final_path = build_path(paths[j], cmd);
				if(access(final_path, F_OK | X_OK) == 0)
				{
					return(final_path);
				}
				free(final_path);
				j++;
			}
		}
		index++;
	}
	return (NULL);
}
