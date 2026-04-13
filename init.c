/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:33:03 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 18:58:55 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	init_type(const char *format, t_list *info, t_flags *flags)
{
	info->type = format[info->index];
	conflict_remove(flags, info);
	if (info->type == 'i' || info->type == 'd')
		print_int(info, flags);
	else if (info->type == 'x' || info->type == 'X')
		print_hex(info, flags);
	else if (info->type == 'u')
		print_unsigned(info, flags);
	else if (info->type == 's')
		print_string(info, flags);
	else if (info->type == 'p')
		print_pointer(info, flags);
	else if (info->type == 'c')
		print_char(info, flags);
	else if (info->type == '%')
		ft_put_n_char(info, '%', 1);
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

int	non_type(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'X' || format[i] == 'x' || format[i] == 'p'
			|| format[i] == 's' || format[i] == 'c' || format[i] == '%')
			return (1);
		i++;
	}
	return (0);
}
