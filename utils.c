#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putchar(char c, t_list *info)
{
	write(1, &c, 1);
	info->count++;
}

void	conflict_remove(t_flags *flags)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->precesion >= 0)
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
}
