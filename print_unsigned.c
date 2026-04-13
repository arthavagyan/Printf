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

static void	return_char_number(t_flags *flags, t_bonus *bonus)
{
	bonus->number_char = ft_itoa(bonus->number_u);
	if (flags->dot && flags->precision == 0 && bonus->number_u == 0)
	{
		free(bonus->number_char);
		bonus->number_char = ft_strdup("");
	}
}

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	int	num_len;

	num_len = ft_strlen(bonus->number_char);
	bonus->zero_count = 0;
	bonus->space_count = 0;
	if (flags->dot && flags->precision > num_len)
		bonus->zero_count = flags->precision - num_len;
	else if (flags->zero && flags->width > 0 && !flags->minus && !flags->dot)
		bonus->zero_count = flags->width - num_len;
	bonus->total_val_len = bonus->zero_count + num_len;
	if (flags->width > bonus->total_val_len)
		bonus->space_count = flags->width - bonus->total_val_len;
}

static void	assemble_number(t_list *info, t_flags *flags, t_bonus *bonus)
{
	int	i;

	i = 0;
	if (!flags->minus && (!flags->zero || !flags->dot))
		ft_put_n_char(info, ' ', bonus->space_count);
	if (!flags->minus && flags->zero && !flags->dot)
		ft_put_n_char(info, '0', bonus->space_count);
	ft_put_n_char(info, '0', bonus->zero_count);
	while (bonus->number_char[i])
	{
		ft_put_n_char(info, bonus->number_char[i], 1);
		i++;
	}
	if (flags->minus && bonus->space_count > 0)
		ft_put_n_char(info, ' ', bonus->space_count);
}

void	print_unsigned(t_list *info, t_flags *flags)
{
	t_bonus	bonus;

	bonus.number_u = va_arg(info->args, unsigned int);
	return_char_number(flags, &bonus);
	return_total_len(flags, &bonus);
	assemble_number(info, flags, &bonus);
	free(bonus.number_char);
}
