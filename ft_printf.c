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
/*
int	main(void)
{
	// ft_printf("|%+d|\n", 42);  //|+42| 1
	// ft_printf("|% d|\n", 42);  //| 42| 2
	// ft_printf("|%+d|\n", -42); //|-42| 3 
	// ft_printf("|% d|\n", -42); //|-42| 4
	// ft_printf("|%05d|\n", 42); //|00042| 5
	// ft_printf("|%05d|\n", -42);//|-0042| 6
	// ft_printf("|%-5d|\n", 42); //|42   |  7
	// ft_printf("|%-5d|\n", -42);//|-42  |  8
	// ft_printf("|%5d|\n", 42);  //|   42| 9
	// ft_printf("|%5d|\n", -42); //|  -42| 10 
	// ft_printf("|%.5d|\n", 42); //|00042|  11
	// ft_printf("|%.5d|\n", -42);//|-00042|  12
	// ft_printf("|%.0d|\n", 0);  //||   13
	// ft_printf("|%8.5d|\n", 42);//|   00042| 14
	// ft_printf("|%-05d|\n", 42);//|42   | 15
	// ft_printf("|%+ d|\n", 42); //|+42|  16
	// ft_printf("|%08.5d|\n", 42);//|   00042|  17
	// ft_printf("|%+-10.5d|\n", 42);//|+00042    | 18
	// ft_printf("|%08.3d|\n", 42);//|     042| 19
	// ft_printf("|%+- 10.5d|\n", 42); 
	// ft_printf("|%+- 10.5d|\n", -42);
	// ft_printf("|%10.5d|\n", -42);
	// ft_printf("|%.0d|\n", 0);
	// ft_printf("|%5.0d|\n", 0);
	// ft_printf("|%-5.0d|\n", 0);
	// ft_printf("|%010.5d|\n", 42);
	// ft_printf("|%010.5d|\n", -42);
	// ft_printf("|%-010d|\n", 42);
	// ft_printf("|%-010d|\n", -42);
	// ft_printf("|%+ d|\n", 42);
	// ft_printf("|%+ d|\n", -42);
	// ft_printf("|%3.5d|\n", 42);
	// ft_printf("|%3.5d|\n", -42);
	// ft_printf("|%20.10d|\n", 1234);
	// ft_printf("|%-20.10d|\n", 1234);
	// ft_printf("|%+010d|\n", 42);
	// ft_printf("|%010d|\n", -42);
	// ft_printf("|%+5d|\n", 0);
	// ft_printf("|% 5d|\n", 0);
	// ft_printf("|%+.0d|\n", 0);
	// ft_printf("|% .0d|\n", 0);
	// ft_printf("|%+-15.8d|\n", 123);
	// ft_printf("|%+-15.8d|\n", -123);
	ft_printf("%d", -2147483648);
	return (0);
}
*/
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
