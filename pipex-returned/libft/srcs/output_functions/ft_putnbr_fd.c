/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:57:48 by abrisse           #+#    #+#             */
/*   Updated: 2021/11/28 03:00:51 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_aux(long n, int fd)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	if (n < 10)
		return (ft_putchar_fd(n + '0', fd));
	ft_putnbr_fd_aux(n / 10, fd);
	ft_putnbr_fd_aux(n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr_fd_aux(n, fd);
}
