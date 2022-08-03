/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:16:57 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 20:16:58 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned long long n, int len_base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / len_base;
		i++;
	}
	return (i);
}

char	*ft_uitoa_base(unsigned long long n, char *base)
{
	char	*ret;
	int		i;

	i = ft_len(n, ft_strlen(base));
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (--i >= 0)
	{
		ret[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	return (ret);
}
