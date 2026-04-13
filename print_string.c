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

static void	null_check(t_flags *flags, t_bonus *bonus)
{
	bonus->null_index = 0;
	if (!bonus->str)
	{
		if ((flags->dot && flags->precision >= 6) || !flags->dot)
		{
			bonus->str = ft_strdup("(null)");
			bonus->null_index = 1;
		}
		else
		{
			bonus->str = ft_strdup("");
			bonus->null_index = 1;
		}
	}
}

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	int	str_len;

	bonus->str_limit = 0;
	bonus->space_count = 0;
	str_len = ft_strlen(bonus->str);
	if (flags->dot && flags->precision < str_len)
		bonus->str_limit = flags->precision;
	else
		bonus->str_limit = str_len;
	if (flags->width > bonus->str_limit)
		bonus->space_count = flags->width - bonus->str_limit;
}

static void	assemble_number(t_list *info, t_flags *flags, t_bonus *bonus)
{
	int	i;

	i = 0;
	if (!flags->minus)
		ft_put_n_char(info, ' ', bonus->space_count);
	while (i < bonus->str_limit)
	{
		ft_put_n_char(info, bonus->str[i], 1);
		i++;
	}
	if (flags->minus && bonus->space_count > 0)
		ft_put_n_char(info, ' ', bonus->space_count);
}

void	print_string(t_list *info, t_flags *flags)
{
	t_bonus	bonus;

	bonus.str = va_arg(info->args, char *);
	null_check(flags, &bonus);
	return_total_len(flags, &bonus);
	assemble_number(info, flags, &bonus);
	if (bonus.null_index)
		free(bonus.str);
}
