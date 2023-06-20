/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:34:23 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:19:01 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_base(t_buffer *buff, t_info *info, char *base)
{
	unsigned int	nbr;

	nbr = va_arg(buff->args, unsigned int);
	info->argument = ft_uitoa_base(nbr, base);
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
	if (nbr)
		printf_add_prefix(info, 0);
	if (!info->left_justify)
		printf_left_padding(info, info->padding, info->width);
	else
		printf_right_padding(info, ' ', info->width);
	info->len = ft_strlen(info->argument);
}
