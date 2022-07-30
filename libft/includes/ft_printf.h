/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrisse <abrisse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:35:50 by abrisse           #+#    #+#             */
/*   Updated: 2022/03/03 02:20:28 by abrisse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# elif __linux__
#  define PTR_NULL "(nil)"
# endif

typedef struct s_buffer
{
	const char	*format;
	va_list		args;
	size_t		i;
	size_t		len;
}			t_buffer;

typedef struct s_info
{
	int		left_justify;
	char	*prefix;
	char	padding;
	int		width;
	int		precision;
	char	type;
	char	*argument;
	size_t	len;
}			t_info;

/* ft_printf.c */
int			ft_printf(const char *format, ...);
void		printf_aux(t_buffer *buff);
t_buffer	*printf_init_buffer(const char *format, va_list args);
t_info		*printf_init_info(void);

/* get_info.c */
void		*printf_get_info(t_buffer *buff, t_info *info);
void		printf_get_flags(t_buffer *buff, t_info *info);
void		printf_get_width(t_buffer *buff, t_info *info);
void		printf_get_precision(t_buffer *buff, t_info *info);
void		printf_get_type(t_buffer *buff, t_info *info);

/* get_conversion.c */
void		printf_conversion(t_buffer *buff, t_info *info);

/* printf_char.c */
void		printf_char(t_buffer *buff, t_info *info);

/* printf_str.c */
void		printf_str(t_buffer *buff, t_info *info);

/* printf_ptr.c */
void		printf_ptr(t_buffer *buff, t_info *info);

/* printf_int.c */
void		printf_int(t_buffer *buff, t_info *info);
void		printf_int_flags(t_info *info, int sign);

/* printf_base.c */
void		printf_base(t_buffer *buff, t_info *info, char *base);

/* printf_pct.c */
void		printf_pct(t_info *info);

/* utils.c */
void		printf_left_padding(t_info *info, char padding, int width);
void		printf_right_padding(t_info *info, char padding, int width);
void		printf_add_prefix(t_info *info, int sign);
void		printf_int_prefix(t_info *info, int sign);
void		printf_base_prefix(t_info *info);

#endif
