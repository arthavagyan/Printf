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

void	print_unsigned(t_list *info, t_flags *flags)
{
	t_digit	digit;
	int		number_unsigned_int;

	number_unsigned_int = va_arg(info->args, unsigned int);
	digit.number = (long)number_unsigned_int;
	return_char_number(flags, &digit);
	return_total_len(flags, &digit);
	assemble_number(info, flags, &digit);
	free(digit.number_char);	
}
