/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 20:20:13 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 18:58:23 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	bonus->space_count = 0;
	if (flags->width > 1)
		bonus->space_count = flags->width - 1;
}

static void	assemble_char(t_list *info, t_flags *flags, t_bonus *bonus)
{
	if (!flags->minus)
		ft_put_n_char(info, ' ', bonus->space_count);
	ft_put_n_char(info, bonus->symbol, 1);
	if (flags->minus)
		ft_put_n_char(info, ' ', bonus->space_count);
}

void	print_char(t_list *info, t_flags *flags)
{
	t_bonus	bonus;

	bonus.symbol = (char)va_arg(info->args, int);
	return_total_len(flags, &bonus);
	assemble_char(info, flags, &bonus);
}
