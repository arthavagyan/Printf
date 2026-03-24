/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:59:16 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/23 13:59:21 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Printf Bonus Flag check%-+ #10.3");
}

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
			ft_putchar(format[info.index], &info);
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
