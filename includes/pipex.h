/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:32:51 by abrisse           #+#    #+#             */
/*   Updated: 2022/08/29 12:39:05 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/* process.c */
void	child_process(int fd1, int *end, char *cmd, char **env);
void	parent_process(int fd2, int *end, char *cmd, char **env);

/* error.c */
void	ft_error(const char *msg);

#endif
