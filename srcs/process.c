/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:16:44 by abrisse           #+#    #+#             */
/*   Updated: 2022/08/02 17:45:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**free_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (NULL);
}

static char	**get_paths(char **env)
{
	int		i;
	char	**my_paths;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		ft_error("Error: PATH not find");
	my_paths = ft_split(env[i] + 5, ':');
	return (my_paths);
}

static void	exec_cmd(char *cmd, char **env)
{
	char	**my_paths;
	char	**cmd_args;
	int		i;

	cmd_args = ft_split(cmd, ' ');
	if (ft_strchr(cmd_args[0], '/') != NULL)
		execve(cmd_args[0], cmd_args, env);
	else
	{
		my_paths = get_paths(env);
		i = -1;
		while (my_paths[++i])
		{
			my_paths[i] = ft_strjoin_free(my_paths[i], "/");
			my_paths[i] = ft_strjoin_free(my_paths[i], cmd_args[0]);
			execve(my_paths[i], cmd_args, env);
		}
		free_split(my_paths);
	}
	free_split(cmd_args);
	ft_putendl_fd("Error: Command not found", STDERR);
	exit(EXIT_FAILURE);
}

void	child_process(int fd1, int *end, char *cmd, char **env)
{
	close(end[0]);
	if (fd1 >= 0)
		dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	close(fd1);
	if (fd1 >= 0)
		exec_cmd(cmd, env);
	exit(EXIT_FAILURE);
}

void	parent_process(int fd2, int *end, char *cmd, char **env)
{
	close(end[1]);
	if (fd2 >= 0)
		dup2(fd2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	close(fd2);
	if (fd2 >= 0)
		exec_cmd(cmd, env);
	exit(EXIT_FAILURE);
}
