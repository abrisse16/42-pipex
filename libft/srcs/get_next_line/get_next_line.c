/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 01:22:30 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/21 19:42:55 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buff(int fd, char *save)
{
	char	*buff;
	int		ret_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ret_read = 1;
	while (!gnl_strchr(save, '\n') && ret_read != 0)
	{
		if (ret_read == -1)
		{
			free(buff);
			return (NULL);
		}
		ret_read = read(fd, buff, BUFFER_SIZE);
		buff[ret_read] = '\0';
		save = gnl_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clear(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	new_save = malloc(sizeof(char) * (gnl_strlen(save) - i + 1));
	if (!new_save)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[FD_SETSIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	save[fd] = get_buff(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = get_line(save[fd]);
	save[fd] = clear(save[fd]);
	return (line);
}
