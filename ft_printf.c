/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:59:16 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 20:47:08 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	info;

	va_start(info.args, format);
	info.index = 0;
	info.count = 0;
	while (format[info.index])
	{
		if (format[info.index] != '%')
		{
			ft_put_n_char(&info, format[info.index], 1);
			info.index++;
		}
		else
		{
			info.index++;
			parse_format(format, &info);
		}
	}
	va_end(info.args);
	return (info.count);
}
