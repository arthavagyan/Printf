/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:10:41 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/13 23:08:26 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	hex_len(t_bonus *bonus)
{
	int					len;
	unsigned long long	number;

	number = bonus->pointer_number;
	len = 1;
	while (number >= 16)
	{
		len++;
		number /= 16;
	}
	return (len);
}

static void	return_hex_format(t_bonus *bonus)
{
	int					len;
	unsigned long long	number;
	char				*base;

	base = "0123456789abcdef";
	len = hex_len(bonus) + 2;
	bonus->number_char = malloc(len + 1);
	if (!(bonus->number_char))
		return ;
	bonus->number_char[0] = '0';
	bonus->number_char[1] = 'x';
	bonus->number_char[len] = '\0';
	if (!bonus->pointer_number)
	{
		free(bonus->number_char);
		bonus->number_char = ft_strdup("(nil)");
	}
	number = bonus->pointer_number;
	while (number > 0)
	{
		bonus->number_char[len - 1] = base[number % 16];
		len--;
		number /= 16;
	}
}

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	int	num_len;

	num_len = ft_strlen(bonus->number_char);
	bonus->space_count = 0;
	if (flags->width > num_len)
		bonus->space_count = flags->width - num_len;
}

static void	assemble_number(t_list *info, t_flags *flags, t_bonus *bonus)
{
	int	i;

	i = 0;
	if (!flags->minus && (!flags->zero || !flags->dot))
		ft_put_n_char(info, ' ', bonus->space_count);
	while (bonus->number_char[i])
	{
		ft_put_n_char(info, bonus->number_char[i], 1);
		i++;
	}
	if (flags->minus && bonus->space_count > 0)
		ft_put_n_char(info, ' ', bonus->space_count);
}

void	print_pointer(t_list *info, t_flags *flags)
{
	t_bonus	bonus;
	void	*ptr;

	ptr = va_arg(info->args, void *);
	bonus.pointer_number = (unsigned long long)ptr;
	return_hex_format(&bonus);
	return_total_len(flags, &bonus);
	assemble_number(info, flags, &bonus);
	free(bonus.number_char);
}
