/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:31:26 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/21 19:35:28 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, char c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gnl_strlen(src));
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	len1;
	size_t	len2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	ret = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len1 + 1);
	ft_strlcpy(ret + len1, s2, len2 + 1);
	free(s1);
	return (ret);
}
