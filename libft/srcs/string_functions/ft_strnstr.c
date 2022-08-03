/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 04:05:13 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/27 04:17:49 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*(haystack + i) == *(needle + i) && len - i > 0)
		{
			if (*(needle + i + 1) == '\0')
				return ((char *)haystack);
			i++;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
