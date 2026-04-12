/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:32:25 by artavagy          #+#    #+#             */
/*   Updated: 2026/03/29 19:05:08 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void	conflict_remove(t_flags *flags, t_list *info)
{
	if (flags->minus)
		flags->zero = 0;
	if (flags->precision >= 0 && (info->type != 's' || info->type != 'c'))
		flags->zero = 0;
	if (flags->plus)
		flags->space = 0;
	if (flags->hash && (info->type != 'x' || info->type != 'X'))
		flags->hash = 0;
}