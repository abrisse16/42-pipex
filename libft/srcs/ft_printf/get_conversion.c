/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 23:56:48 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/02 20:58:17 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_conversion(t_buffer *buff, t_info *info)
{	
	if (info->type == 'c')
		printf_char(buff, info);
	else if (info->type == 's')
		printf_str(buff, info);
	else if (info->type == 'p')
		printf_ptr(buff, info);
	else if (info->type == 'd' || info->type == 'i')
		printf_int(buff, info);
	else if (info->type == 'u')
		printf_base(buff, info, "0123456789");
	else if (info->type == 'x')
		printf_base(buff, info, "0123456789abcdef");
	else if (info->type == 'X')
		printf_base(buff, info, "0123456789ABCDEF");
	else
		printf_pct(info);
}
