/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 00:16:56 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:13:49 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_str(t_buffer *buff, t_info *info)
{
	char	*str;

	str = ft_strdup(va_arg(buff->args, char *));
	if (!str)
		str = ft_strdup("(null)");
	info->len = ft_strlen(str);
	if (info->precision != -1)
		info->len = info->precision;
	info->argument = malloc((info->len + 1) * sizeof(char));
	if (!info->argument)
		return ;
	ft_strlcpy(info->argument, str, info->len + 1);
	if (!info->left_justify)
		printf_left_padding(info, ' ', info->width);
	else
		printf_right_padding(info, ' ', info->width);
	info->len = ft_strlen(info->argument);
	free(str);
}
