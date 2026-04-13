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

static int	hex_len(t_bonus *bonus)
{
	int				len;
	unsigned int	number;

	number = bonus->number_u;
	len = 1;
	while (number >= 16)
	{
		len++;
		number /= 16;
	}
	return (len);
}

static void	return_hex_format(t_flags *flags, t_bonus *bonus)
{
	int				len;
	unsigned int	number;

	len = hex_len(bonus);
	bonus->str = malloc(len + 1);
	if (!(bonus->str))
		return ;
	bonus->str[len] = '\0';
	if (bonus->number_u == 0)
	{
		free(bonus->str);
		if ((flags->dot && flags->precision >= 1) || !flags->dot)
			bonus->str = ft_strdup("0");
		else
			bonus->str = ft_strdup("");
	}
	number = bonus->number_u;
	while (number > 0)
	{
		bonus->str[len - 1] = bonus->base[number % 16];
		len--;
		number /= 16;
	}
}

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	int	num_len;

	num_len = ft_strlen(bonus->str);
	bonus->zero_count = 0;
	bonus->sign_len = 0;
	bonus->space_count = 0;
	if (flags->hash && bonus->number_u != 0)
		bonus->sign_len = 2;
	if (flags->dot && flags->precision > num_len)
		bonus->zero_count = flags->precision - num_len;
	else if (flags->zero && flags->width > 0 && !flags->minus && !flags->dot)
		bonus->zero_count = flags->width - num_len - bonus->sign_len;
	bonus->total_val_len = bonus->zero_count + num_len + bonus->sign_len;
	if (flags->width > bonus->total_val_len)
		bonus->space_count = flags->width - bonus->total_val_len;
}

static void	assemble_number(t_list *info, t_flags *flags, t_bonus *bonus)
{
	int	i;

	i = 0;
	if (!flags->minus && (!flags->zero || !flags->dot))
		ft_put_n_char(info, ' ', bonus->space_count);
	if (flags->hash && bonus->number_u != 0)
	{
		ft_put_n_char(info, '0', 1);
		if (bonus->uppercase)
			ft_put_n_char(info, 'X', 1);
		else
			ft_put_n_char(info, 'x', 1);
	}
	if (!flags->minus && flags->zero && !flags->dot)
		ft_put_n_char(info, '0', bonus->space_count);
	ft_put_n_char(info, '0', bonus->zero_count);
	while (bonus->str[i])
	{
		ft_put_n_char(info, bonus->str[i], 1);
		i++;
	}
	if (flags->minus && bonus->space_count > 0)
		ft_put_n_char(info, ' ', bonus->space_count);
}

void	print_hex(t_list *info, t_flags *flags)
{
	t_bonus	bonus;

	bonus.uppercase = 0;
	bonus.base = "0123456789abcdef";
	if (info->type == 'X')
	{
		bonus.uppercase = 1;
		bonus.base = "0123456789ABCDEF";
	}
	bonus.number_u = va_arg(info->args, unsigned int);
	return_hex_format(flags, &bonus);
	return_total_len(flags, &bonus);
	assemble_number(info, flags, &bonus);
	free(bonus.str);
}
