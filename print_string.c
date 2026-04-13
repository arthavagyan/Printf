/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:21:06 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 22:06:20 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	null_check(t_digit *digit)
{
	digit->null_index = 0;
	if (!digit->number_char)
	{
		digit->number_char = ft_strdup("(null)");
		digit->null_index = 1;
	}
}

static void	return_total_len(t_flags *flags, t_digit *digit)
{
	int	str_len;

	digit->str_limit = 0;
	digit->space_count = 0;
	str_len = ft_strlen(digit->number_char);
	if (flags->dot && flags->precision < str_len)
		digit->str_limit = flags->precision;
	else
		digit->str_limit = str_len;
	if (flags->width > digit->str_limit)
		digit->space_count = flags->width - digit->str_limit;
}

static void	assemble_number(t_list *info, t_flags *flags, t_digit *digit)
{
	int	i;

	i = 0;
	if (!flags->minus)
		ft_put_n_char(info, ' ', digit->space_count);
	while (i < digit->str_limit)
	{
		ft_put_n_char(info, digit->number_char[i], 1);
		i++;
	}
	if (flags->minus && digit->space_count > 0)
		ft_put_n_char(info, ' ', digit->space_count);
}

void	print_string(t_list *info, t_flags *flags)
{
	t_digit	digit;

	digit.number_char = va_arg(info->args, char *);
	null_check(&digit);
	return_total_len(flags, &digit);
	assemble_number(info, flags, &digit);
	if (digit.null_index)
		free(digit.number_char);
}
