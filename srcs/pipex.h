/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguedes <lguedes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:16:24 by lguedes           #+#    #+#             */
/*   Updated: 2022/08/24 20:16:25 by lguedes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/src/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

int		ft_check_params(int argc, char *const argv[]);

char	*ft_getpath(char *cmd, char **env);

char	**ft_splitcmd(char *s, char c);

char	*build_path(char *path, char *cmd);

void	ft_closefds(int *fds, size_t fd_nums);

#endif
