/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:52:19 by abrisse           #+#    #+#             */
/*   Updated: 2022/08/02 17:39:54 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_file(char *path, int flag)
{
	int	fd;

	fd = open(path, flag, 0644);
	if (fd < 0)
		perror("Error");
	return (fd);
}	

static void	pipex(int fd1, int fd2, char **av, char **env)
{
	int		end[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(end) == -1)
		ft_error("Error (pipe)");
	pid1 = fork();
	if (pid1 < 0)
		ft_error("Error (fork)");
	if (pid1 == 0)
		child_process(fd1, end, av[2], env);
	pid2 = fork();
	if (pid2 < 0)
		ft_error("Error (fork)");
	if (pid2 == 0)
		parent_process(fd2, end, av[3], env);
	close(end[1]);
	close(end[0]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int	fd1;
	int	fd2;

	if (ac != 5)
	{
		ft_putendl_fd("Error: Invalid number of arguments", STDERR);
		return (EXIT_FAILURE);
	}
	fd1 = open_file(av[1], O_RDONLY);
	fd2 = open_file(av[4], O_WRONLY | O_CREAT | O_TRUNC);
	pipex(fd1, fd2, av, env);
	return (EXIT_SUCCESS);
}
