/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:16:44 by abrisse           #+#    #+#             */
/*   Updated: 2022/07/30 19:26:59 by abrisse          ###   ########.fr       */
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

static void	exec_cmd(char *cmd, char **env)
{
	char	*all_paths;
	char	**my_paths;
	char	**cmd_args;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		ft_error("Error: PATH not find");
	all_paths = env[i] + 5;
	my_paths = ft_split(all_paths, ':');
	cmd_args = ft_split(cmd, ' ');
	i = -1;
	while (my_paths[++i])
	{
		my_paths[i] = ft_strjoin(my_paths[i], "/");
		my_paths[i] = ft_strjoin(my_paths[i], cmd_args[0]);
		execve(my_paths[i], cmd_args, env);
	}
	free_split(my_paths);
	free_split(cmd_args);
	// free join
	ft_putendl_fd("Error: Command not found", STDERR);
	exit(EXIT_FAILURE);
}

void	child_process(int fd1, int *end, char *cmd, char **env)
{
	// add protection if dup2() < 0
	close(end[0]);
	dup2(fd1, STDIN_FILENO);	// Close STDIN, fd1 becomes the new STDIN.
								// fd1 become execve() input.
	dup2(end[1], STDOUT_FILENO);	// Close STDOUT, end[0] becomes the new
									// STDOUT.
									// end[0] becomes execve() output.
	close(end[1]);
	close(fd1);
	exec_cmd(cmd, env);
//	if (WEXITSTATUS(status) == EXIT_FAILURE)
	exit(EXIT_FAILURE);
}

void	parent_process(int fd2, int *end, char *cmd, char **env)
{
	int	status;

	waitpid(-1, &status, 0);
	// add protection if dup2() < 0
	close(end[1]);
	dup2(fd2, STDOUT_FILENO);	// Close STDOUT, fd2 becomes the new STDOUT.
								// fd2 becomes execve() output.
	dup2(end[0], STDIN_FILENO);	// Close STDIN, end[1] becomes the new STDIN.
								// end[1] becomes execve() input.
								// end[1] have end[0] value, who is the output 
								// of the first command.
	close(end[0]);
	close(fd2);
	exec_cmd(cmd, env);
//	if (WEXITSTATUS(status) == EXIT_FAILURE)
	exit(EXIT_FAILURE);
}
