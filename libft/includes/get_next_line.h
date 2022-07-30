/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:27:05 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/21 19:32:51 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_SETSIZE
#  define FD_SETSIZE 1024
# endif

/* get_next_line.c */
char	*get_next_line(int fd);

/* get_next_line_utils.c */
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(char *s, char c);
char	*gnl_strjoin(char *s1, char *s2);

#endif
