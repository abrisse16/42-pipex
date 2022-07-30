/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:08:30 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 20:10:31 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_appendchr(const char *str, const char c)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	new = malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	return (new);
}
