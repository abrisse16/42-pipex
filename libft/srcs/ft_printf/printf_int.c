/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:12:40 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:18:24 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_int(t_buffer *buff, t_info *info)
{
	int			sign;
	long int	nbr;

	sign = 1;
	nbr = va_arg(buff->args, int);
	if (nbr < 0)
		sign = -1;
	info->argument = ft_uitoa_base(sign * nbr, "0123456789");
	if (info->precision != -1)
	{
		if (!info->precision && nbr == 0)
		{
			free(info->argument);
			info->argument = ft_strdup("");
		}
		printf_left_padding(info, '0', info->precision);
		info->padding = ' ';
	}
	printf_int_flags(info, sign);
	info->len = ft_strlen(info->argument);
}

void	printf_int_flags(t_info *info, int sign)
{
	if (info->left_justify == 1)
	{
		printf_add_prefix(info, sign);
		printf_right_padding(info, ' ', info->width);
	}
	else
	{
		if (info->padding == ' ')
		{
			printf_add_prefix(info, sign);
			printf_left_padding(info, info->padding, info->width);
		}
		else if (info->padding == '0')
		{
			if (sign < 0 || ft_strchr(info->prefix, ' ') || \
				ft_strchr(info->prefix, '+'))
				printf_left_padding(info, info->padding, info->width - 1);
			else
				printf_left_padding(info, info->padding, info->width);
			printf_add_prefix(info, sign);
		}
	}
}
