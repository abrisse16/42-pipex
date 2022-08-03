/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:11:14 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 23:24:23 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_char(t_buffer *buff, t_info *info)
{
	char	c;

	c = va_arg(buff->args, int);
	if (!info->width)
		info->width = 1;
	info->argument = malloc(info->width * sizeof(char));
	if (!info->argument)
		return ;
	ft_memset(info->argument, ' ', info->width);
	if (info->left_justify == 1)
		info->argument[0] = c;
	else
		info->argument[info->width - 1] = c;
	info->len = info->width;
}
