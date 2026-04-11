/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:48:07 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 18:16:34 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	print_int(const char *format, t_list *info, t_flags *flags)
{
	printf("\nindex:%ld\ncount:%ld\nminus:%d\nplus:%d\nhash:%d\n"
	"zero:%d\nspace:%d\nwidth:%d\nprecision:%d\ndot:%d\n",
	info->index, info->count,
	flags->minus, flags->plus, flags->hash,
	flags->zero, flags->space,
	flags->width, flags->precesion, flags->dot);
	return ;
}
	/*int		nb;
	char	*nb_char;

	nb = va_arg(info->args, int);
	if (flags->precesion == 0 && nb == 0)
		nb_char = " ";
	else
		nb_char = ft_itoa(nb);
	printf("digit test:%s", nb_char);
	printf("\nprecesion:%d", flags->precesion);*/
