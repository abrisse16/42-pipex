/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:35:49 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/27 03:07:04 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if (ptr_dst < ptr_src)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	else
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	return (dst);
}
