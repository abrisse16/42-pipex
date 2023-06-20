/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:21:48 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:12:42 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*printf_get_info(t_buffer *buff, t_info *info)
{
	printf_get_flags(buff, info);
	printf_get_width(buff, info);
	printf_get_precision(buff, info);
	printf_get_type(buff, info);
	if (!info->type && (ft_strchr("-0# +123456789", buff->format[buff->i])))
		printf_get_info(buff, info);
	return (info);
}

void	printf_get_flags(t_buffer *buff, t_info *info)
{
	char	*tmp;

	if (!info->prefix)
		info->prefix = ft_strdup("");
	while (ft_strchr("-0# +", buff->format[buff->i]))
	{
		if (buff->format[buff->i] == '-')
			info->left_justify = 1;
		if (buff->format[buff->i] == '0')
			info->padding = '0';
		if (ft_strchr("# +", buff->format[buff->i]))
		{
			tmp = info->prefix;
			info->prefix = ft_appendchr(tmp, buff->format[buff->i]);
			free(tmp);
		}
		buff->i++;
	}
}

void	printf_get_width(t_buffer *buff, t_info *info)
{
	if (ft_isdigit(buff->format[buff->i]))
	{
		info->width = 0;
		while (ft_isdigit(buff->format[buff->i]))
		{
			info->width = info->width * 10 + (buff->format[buff->i] - '0');
			buff->i++;
		}
	}
}

void	printf_get_precision(t_buffer *buff, t_info *info)
{
	if (buff->format[buff->i] == '.')
	{
		buff->i++;
		if (!ft_isdigit(buff->format[buff->i]))
			info->precision = 0;
		else
		{
			info->precision = 0;
			while (ft_isdigit(buff->format[buff->i]))
			{
				info->precision *= 10;
				info->precision += buff->format[buff->i] - '0';
				buff->i++;
			}
		}
	}
}

void	printf_get_type(t_buffer *buff, t_info *info)
{
	if (ft_strchr("cspdiuxX%", buff->format[buff->i]))
	{
		info->type = buff->format[buff->i];
		buff->i++;
	}
}
