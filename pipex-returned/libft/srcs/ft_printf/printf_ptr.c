/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:23:31 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:14:30 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_ptr(t_buffer *buff, t_info *info)
{
	void	*ptr;
	char	*nbr;

	nbr = NULL;
	ptr = va_arg(buff->args, void *);
	if (!ptr)
		info->argument = ft_strdup(PTR_NULL);
	else
	{
		nbr = ft_uitoa_base((unsigned long)ptr, "0123456789abcdef");
		info->argument = ft_strjoin("0x", nbr);
		free(nbr);
	}
	if (!info->left_justify)
		printf_left_padding(info, ' ', info->width);
	else
		printf_right_padding(info, ' ', info->width);
	info->len = ft_strlen(info->argument);
}
