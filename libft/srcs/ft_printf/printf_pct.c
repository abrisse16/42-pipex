/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 02:29:58 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:19:41 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_pct(t_info *info)
{
	info->argument = ft_strdup("%");
	if (!info->left_justify)
		printf_left_padding(info, info->padding, info->width);
	else
		printf_right_padding(info, ' ', info->width);
	info->len = ft_strlen(info->argument);
}
