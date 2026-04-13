/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:18:04 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/12 20:06:16 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	return_char_number(t_flags *flags, t_digit *digit)
{
	digit->number_char = ft_itoa(digit->number_u);
	if (flags->dot && flags->precision == 0 && digit->number_u == 0)
	{
		free(digit->number_char);
		digit->number_char = ft_strdup("");
	}
}

static void	return_total_len(t_flags *flags, t_digit *digit)
{
	int	num_len;

	num_len = ft_strlen(digit->number_char);
	digit->zero_count = 0;
	digit->space_count = 0;
	if (flags->dot && flags->precision > num_len)
		digit->zero_count = flags->precision - num_len;
	else if (flags->zero && flags->width > 0 && !flags->minus && !flags->dot)
		digit->zero_count = flags->width - num_len;
	digit->total_val_len = digit->zero_count + num_len;
	if (flags->width > digit->total_val_len)
		digit->space_count = flags->width - digit->total_val_len;
}

static void	assemble_number(t_list *info, t_flags *flags, t_digit *digit)
{
	int	i;

	i = 0;
	if (!flags->minus && (!flags->zero || !flags->dot))
		ft_put_n_char(info, ' ', digit->space_count);
	if (!flags->minus && flags->zero && !flags->dot)
		ft_put_n_char(info, '0', digit->space_count);
	ft_put_n_char(info, '0', digit->zero_count);
	while (digit->number_char[i])
	{
		ft_put_n_char(info, digit->number_char[i], 1);
		i++;
	}
	if (flags->minus && digit->space_count > 0)
		ft_put_n_char(info, ' ', digit->space_count);
}

void	print_unsigned(t_list *info, t_flags *flags)
{
	t_digit	digit;

	digit.number_u = va_arg(info->args, unsigned int);
	return_char_number(flags, &digit);
	return_total_len(flags, &digit);
	assemble_number(info, flags, &digit);
	free(digit.number_char);
}
