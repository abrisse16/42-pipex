/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 22:25:38 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/27 03:05:07 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;

	if (!dst && !src)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	while (n > 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (dst);
}
