/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:19:38 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:24:00 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_left_padding(t_info *info, char padding, int width)
{
	char	*tmp;
	size_t	strlen;

	strlen = ft_strlen(info->argument);
	if (!width || width < (int)strlen)
		width = strlen;
	tmp = malloc(width * sizeof(char));
	if (!tmp)
		return ;
	ft_memset(tmp, padding, width - strlen);
	tmp[width - strlen] = '\0';
	ft_strlcat(tmp, info->argument, width + 1);
	free(info->argument);
	info->argument = tmp;
}

void	printf_right_padding(t_info *info, char padding, int width)
{
	char	*tmp;
	size_t	strlen;

	strlen = ft_strlen(info->argument);
	if (!width || width < (int)strlen)
		width = strlen;
	tmp = (char *)malloc(width * sizeof(char));
	if (!tmp)
		return ;
	ft_strlcpy(tmp, info->argument, strlen + 1);
	ft_memset(&tmp[strlen], padding, width - strlen);
	tmp[width] = '\0';
	free(info->argument);
	info->argument = tmp;
}

void	printf_add_prefix(t_info *info, int sign)
{
	if (info->type == 'd' || info->type == 'i')
		printf_int_prefix(info, sign);
	else if (info->type == 'x' || info->type == 'X')
		printf_base_prefix(info);
}

void	printf_int_prefix(t_info *info, int sign)
{
	int	len;

	len = ft_strlen(info->argument) + 1;
	if (ft_strchr(info->prefix, '+') && sign == 1)
		printf_left_padding(info, '+', len);
	else if (ft_strchr(info->prefix, ' ') && sign == 1)
		printf_left_padding(info, ' ', len);
	else if (sign == -1)
		printf_left_padding(info, '-', len);
}

void	printf_base_prefix(t_info *info)
{
	char	*tmp;

	tmp = info->argument;
	if (ft_strchr(info->prefix, '#'))
	{
		if (info->type == 'x')
			info->argument = ft_strjoin("0x", tmp);
		if (info->type == 'X')
			info->argument = ft_strjoin("0X", tmp);
		free(tmp);
	}
}
