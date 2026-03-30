/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:33:03 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/29 17:14:33 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	init_type(const char *format, t_list *info, t_flags *flags)
{
	char	c;

	printf("\nindex:%ld\ncount:%ld\nminus:%d\nplus:%d\nhash:%d\n"
		"zero:%d\nspace:%d\nwidth:%d\nprecision:%d\ndot:%d\n",
		info->index, info->count,
		flags->minus, flags->plus, flags->hash,
		flags->zero, flags->space,
		flags->width, flags->precesion, flags->dot);
	c = format[info->index];
	if (c == 'i' || c == 'd')
		print_int(format, info, flags);
/*	else if (c == 'x')
		print_hex_lower(format, info, flags);
	else if (c == 'X')
		print_hex_upper(format, info, flags);
	else if (c == 'u')
		print_unsigned(format, info, flags);
	else if (c == 's')
		print_string(format, info, flags);
	else if (c == 'c')
		print_char(format, info, flags);
	info->index++;
*/
}

void	init_flags(const char *format, t_list *info, t_flags *flags)
{
	while (format[info->index] == '#' || format[info->index] == '+'
		|| format[info->index] == '-' || format[info->index] == '0'
		|| format[info->index] == ' ')
	{
		if (format[info->index] == '#')
			flags->hash = 1;
		if (format[info->index] == '+')
			flags->plus = 1;
		if (format[info->index] == '-')
			flags->minus = 1;
		if (format[info->index] == '0')
			flags->zero = 1;
		if (format[info->index] == ' ')
			flags->space = 1;
		info->index++;
	}
	conflict_remove(flags);
}
