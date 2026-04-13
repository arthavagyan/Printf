/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:54:06 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 21:16:38 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	hex_len(t_digit *digit)
{
	int				len;
	unsigned int	number;

	number = digit->number_u;
	len = 1;
	while (number >= 16)
	{
		len++;
		number /= 16;
	}
	return (len);
}

static void	return_hex_format(t_digit *digit)
{
	int				len;
	unsigned int	number;
	char			*base;

	base = "0123456789abcdef";
	if (digit->uppercase)
		base = "0123456789ABCDEF";
	len = hex_len(digit);
	digit->number_char = malloc(len + 1);
	if (!(digit->number_char))
		return ;
	digit->number_char[len] = '\0';
	if (digit->number_u == 0)
	{
		free(digit->number_char);
		digit->number_char = ft_strdup("0");
	}
	number = digit->number_u;
	while (number > 0)
	{
		digit->number_char[len - 1] = base[number % 16];
		len--;
		number /= 16;
	}
}

static void	return_total_len(t_flags *flags, t_digit *digit)
{
	int	num_len;

	num_len = ft_strlen(digit->number_char);
	digit->zero_count = 0;
	digit->sign_len = 0;
	digit->space_count = 0;
	if (flags->hash && digit->number_u != 0)
		digit->sign_len = 2;
	if (flags->dot && flags->precision > num_len)
		digit->zero_count = flags->precision - num_len;
	else if (flags->zero && flags->width > 0 && !flags->minus && !flags->dot)
		digit->zero_count = flags->width - num_len - digit->sign_len;
	digit->total_val_len = digit->zero_count + num_len + digit->sign_len;
	if (flags->width > digit->total_val_len)
		digit->space_count = flags->width - digit->total_val_len;
}

static void	assemble_number(t_list *info, t_flags *flags, t_digit *digit)
{
	int	i;

	i = 0;
	if (!flags->minus && (!flags->zero || !flags->dot))
		ft_put_n_char(info, ' ', digit->space_count);
	if (flags->hash && digit->number_u != 0)
	{
		ft_put_n_char(info, '0', 1);
		if (digit->uppercase)
			ft_put_n_char(info, 'X', 1);
		else
			ft_put_n_char(info, 'x', 1);
	}
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

void	print_hex(t_list *info, t_flags *flags)
{
	t_digit	digit;

	digit.uppercase = 0;
	if (info->type == 'X')
		digit.uppercase = 1;
	digit.number_u = va_arg(info->args, unsigned int);
	return_hex_format(&digit);
	return_total_len(flags, &digit);
	assemble_number(info, flags, &digit);
	free(digit.number_char);
}
