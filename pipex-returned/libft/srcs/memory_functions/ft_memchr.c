/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:49:17 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/27 03:57:19 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		uc;

	ptr_s = (unsigned char *)s;
	uc = (unsigned char)c;
	while (n > 0)
	{
		if (*ptr_s == uc)
			return ((void *)ptr_s);
		n--;
		ptr_s++;
	}
	return (NULL);
}
