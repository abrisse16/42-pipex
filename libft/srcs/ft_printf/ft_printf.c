/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:22:18 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 22:11:16 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			len;
	t_buffer	*buff;

	if (format == NULL)
		return (0);
	va_start(args, format);
	buff = printf_init_buffer(format, args);
	if (!buff)
		return (0);
	while (buff->format[buff->i])
	{
		if (buff->format[buff->i] == '%')
			printf_aux(buff);
		else
			buff->len += write(1, &buff->format[buff->i++], 1);
	}	
	len = buff->len;
	free(buff);
	va_end(args);
	return (len);
}

void	printf_aux(t_buffer *buff)
{
	t_info	*info;

	info = printf_init_info();
	buff->i++;
	printf_get_info(buff, info);
	if (info->type)
	{
		printf_conversion(buff, info);
		buff->len += write(1, info->argument, info->len);
		free(info->argument);
	}
	free(info->prefix);
	free(info);
}

t_buffer	*printf_init_buffer(const char *format, va_list args)
{
	t_buffer	*buff;

	buff = malloc(sizeof(t_buffer));
	if (!buff)
		return (NULL);
	buff->format = format;
	va_copy(buff->args, args);
	buff->i = 0;
	buff->len = 0;
	return (buff);
}

t_info	*printf_init_info(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->left_justify = 0;
	info->prefix = ft_strdup("");
	info->padding = ' ';
	info->width = 0;
	info->precision = -1;
	info->type = '\0';
	info->argument = NULL;
	info->len = 0;
	return (info);
}
