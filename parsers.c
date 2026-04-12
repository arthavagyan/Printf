/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:32:40 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/29 18:11:57 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	parse_width(const char *format, t_list *info, t_flags *flags)
{
	flags->width = 0;
	if (format[info->index] == '*')
	{
		flags->width = va_arg(info->args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
		info->index++;
	}
	while (ft_isdigit(format[info->index]))
	{
		flags->width = flags->width * 10 + (format[info->index] - '0');
		info->index++;
	}
}

void	parse_precision(const char *format, t_list *info, t_flags *flags)
{
	flags->precision = -1;
	if (format[info->index] == '.')
	{
		flags->dot = 1;
		flags->precision = 0;
		info->index++;
		if (format[info->index] == '*')
		{
			flags->precision = va_arg(info->args, int);
			info->index++;
		}
		while (ft_isdigit(format[info->index]))
		{
			flags->precision = flags->precision * 10
				+ (format[info->index] - '0');
			info->index++;
		}
	}
}

void	parse_format(const char *format, t_list *info)
{
	if (format[info->index] && format[info->index] == '%')
	{
		ft_putchar(format[info->index], info);
		info->index++;
		return ;
	}
	else
		parse_flags(format, info);
}

void	parse_flags(const char *format, t_list *info)
{
	t_flags	flags;

	flag_zero_fill(&flags);
	init_flags(format, info, &flags);
	parse_width(format, info, &flags);
	parse_precision(format, info, &flags);
	init_type(format, info, &flags);
}

void	flag_zero_fill(t_flags *flags)
{
	flags->hash = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->dot = 0;
}
