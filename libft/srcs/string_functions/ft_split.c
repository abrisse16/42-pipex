/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:21:16 by abrisse           #+#    #+#             */
/*   Updated: 2021/12/08 20:52:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_word(int *index, char const *s, char c)
{
	int		len;
	char	*word;
	int		i;

	i = 0;
	len = 0;
	while (s[*index] == c)
		(*index)++;
	while (s[*index + len] != c && s[*index + len])
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i++] = s[*index];
		(*index)++;
	}
	word[i] = 0;
	return (word);
}

static char	**free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		word_count;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	ret = malloc(sizeof(char *) * (word_count + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		ret[i] = get_word(&j, s, c);
		if (!ret[i])
			return (free_split(ret));
		i++;
	}
	ret[i] = 0;
	return (ret);
}
