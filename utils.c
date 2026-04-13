/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:32:25 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 18:57:58 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_put_n_char(t_list *info, char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		info->count++;
		i++;
	}
}

void	ft_putchar(char c, t_list *info)
{
	write(1, &c, 1);
	info->count++;
}

static void	conflict_type_remove(t_flags *flags, t_list *info)
{
	if (info->type == 'u')
	{
		if (flags->precision != -1)
			flags->zero = 0;
		flags->space = 0;
		flags->plus = 0;
	}
	if (info->type == 'c')
	{
		flags->zero = 0;
		flags->plus = 0;
		flags->space = 0;
		flags->dot = 0;
		flags->precision = -1;
	}
	if (info->type == 'x' || info->type == 'X')
	{
		flags->plus = 0;
		flags->space = 0;
	}
}

void	conflict_remove(t_flags *flags, t_list *info)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->precision >= 0 && (info->type != 's' || info->type != 'c'))
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->hash && info->type != 'x' && info->type != 'X')
		flags->hash = 0;
	if (info->type == 's')
	{
		flags->zero = 0;
		flags->plus = 0;
		flags->space = 0;
		flags->hash = 0;
	}
	conflict_type_remove(flags, info);
}
