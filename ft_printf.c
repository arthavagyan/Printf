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

int	main(void)
{
	ft_printf("%-d");// minus
	printf("\n\n");
	ft_printf("%0d");// zero
	printf("\n\n");
	ft_printf("%+d");// plus
	printf("\n\n");
	ft_printf("% d");// space
	printf("\n\n");
	ft_printf("%#d");// hash
	printf("\n\n");
	ft_printf("%-0d");// minus zero
	printf("\n\n");
	ft_printf("%0-d");// zero minus
	printf("\n\n");
	ft_printf("%+-d");// plus minus
	printf("\n\n");
	ft_printf("% -+d");// space minus plus
	printf("\n\n");
	ft_printf("%5d");// width 5
	printf("\n\n");
	ft_printf("%123d");// width 123
	printf("\n\n");
	ft_printf("%.5d");// precesion 5
	printf("\n\n");
	ft_printf("%.123d");// precesion 123
	printf("\n\n");
	ft_printf("%5.3d");// width 5 precesion 3
	printf("\n\n");
	ft_printf("%10.0d");// width 10 precesion 0
	printf("\n\n");
	ft_printf("%-5d");// minus width 5
	printf("\n\n");
	ft_printf("%05d");// zero width 5
	printf("\n\n");
	ft_printf("%+8d");// plus width 8
	printf("\n\n");
	ft_printf("%-.5d");// minus precesion 5
	printf("\n\n");
	ft_printf("%+.3d");// plus precesion 3
	printf("\n\n");
	ft_printf("% .5d");// space precesion 5
	printf("\n\n");
	ft_printf("%-5.3d");// minus width 5 precesion 3
	printf("\n\n");
	ft_printf("%05.3d");// zero width 5 precesion 3
	printf("\n\n");
	ft_printf("%+8.4d");// plus width 8 precesion 4
	printf("\n\n");
	ft_printf("% -#10.5d");// space minus hash width 10 precesion 5
	printf("\n\n");
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
