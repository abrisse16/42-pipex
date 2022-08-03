/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:34:01 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/28 02:43:49 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		neg;
	long	nb;

	nb = n;
	i = ft_len(nb);
	neg = 0;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
		neg = 1;
	}
	ret[i] = '\0';
	while (--i >= neg)
	{
		ret[i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (ret);
}
