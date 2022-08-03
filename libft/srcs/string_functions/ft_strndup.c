/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:16:44 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 20:16:54 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (size > n)
		size = n;
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, size + 1);
	return (copy);
}
