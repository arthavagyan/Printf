/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:59:41 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/12 20:23:19 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	va_list	args;
	size_t	index;
	size_t	count;
	char	type;
}		t_list;

typedef struct f_list
{
	int	hash;
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	width;
	int	precision;
	int	dot;
}		t_flags;

typedef struct d_list
{
	long	number;
	int		sign_len;
	int		zero_count;
	int		space_count;
	int		total_val_len;
	unsigned int	number_u;
	char	sign;
	char	*number_char;
}		t_digit;

int		ft_printf(const char *format, ...);
int		ft_isdigit(int c);

void	parse_precesion(const char *format, t_list *info, t_flags *flags);
void	parse_width(const char *format, t_list *info, t_flags *flags);
void	init_flags(const char *format, t_list *info, t_flags *flags);
void	init_type(const char *format, t_list *info, t_flags *flags);
void	parse_format(const char *format, t_list *info);
void	parse_flags(const char *format, t_list *info);
void	conflict_remove(t_flags *flags, t_list *info);
void	print_unsigned(t_list *info, t_flags *flags);
//void	print_hex_upper(t_list *info, t_flags *flags);
//void	print_hex_lower(t_list *info, t_flags *flags);
void	ft_put_n_char(t_list *info, char c, int n);
//void	print_string(t_list *info, t_flags *flags);
void	print_int(t_list *info, t_flags *flags);
//void	print_char(t_list *info, t_flags *flags);
void	ft_putchar(char c, t_list *info);
void	flag_zero_fill(t_flags *flags);

size_t	number_len(long number);
size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(long n);
#endif
