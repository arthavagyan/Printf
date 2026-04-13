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
	bonus->str = malloc(len + 1);
	if (!(bonus->str))
		return ;
	bonus->str[0] = '0';
	bonus->str[1] = 'x';
	bonus->str[len] = '\0';
	if (!bonus->pointer_number)
	{
		free(bonus->str);
		bonus->str = ft_strdup("(nil)");
	}
	number = bonus->pointer_number;
	while (number > 0)
	{
		bonus->str[len - 1] = base[number % 16];
		len--;
		number /= 16;
	}
}

static void	return_total_len(t_flags *flags, t_bonus *bonus)
{
	int	num_len;

	num_len = ft_strlen(bonus->str);
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
	while (bonus->str[i])
	{
		ft_put_n_char(info, bonus->str[i], 1);
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
	free(bonus.str);
}
