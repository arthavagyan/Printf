/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:33:03 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 18:22:06 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	init_type(const char *format, t_list *info, t_flags *flags)
{
	char	c;

	info->type = format[info->index];
	conflict_remove(flags, info);
	if (info->type == 'i' || info->type == 'd')
		print_int(format, info, flags);
	else if (info->type == 'x')
		print_hex_lower(format, info, flags);
	else if (info->type == 'X')
		print_hex_upper(format, info, flags);
	else if (info->type == 'u')
		print_unsigned(format, info, flags);
	else if (info->type == 's')
		print_string(format, info, flags);
	else if (info->type == 'c')
		print_char(format, info, flags);
	info->index++;
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
}
