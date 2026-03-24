#include "ft_printf.h"

void	init_type(const char *format, t_list *info, t_flags *flags)
{
	printf("index:%ld\n", info->index);
	printf("countn:%ld\n", info->count);
	printf("minus:%d\n", flags->minus);
	printf("plus:%d\n", flags->plus);
	printf("hash:%d\n", flags->hash);
	printf("zero:%d\n", flags->zero);
	printf("space:%d\n", flags->space);
	printf("width:%d\n", flags->width);
	printf("precesion:%d\n", flags->precesion);
	printf("dot:%d", flags->dot);
/*
	char	c;

	c = format[info->index];
	if (c == 'i' || c == 'd')
		print_int(format, info, flags);
	else if (c == 'x')
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

