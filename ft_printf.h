/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 13:59:41 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 20:15:27 by artavagy         ###   ########.fr       */
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
}		t_list;

typedef struct f_list
{
	int	hash;
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	width;
	int	precesion;
	int	dot;
}		t_flags;

int		ft_printf(const char *format, ...);
int		ft_isdigit(int c);

void	parse_precesion(const char *format, t_list *info, t_flags *flags);
void	print_hex_upper(const char *format, t_list *info, t_flags *flags);
void	print_hex_lower(const char *format, t_list *info, t_flags *flags);
void	print_unsigned(const char *format, t_list *info, t_flags *flags);
void	parse_width(const char *format, t_list *info, t_flags *flags);
void	print_string(const char *format, t_list *info, t_flags *flags);
void	init_flags(const char *format, t_list *info, t_flags *flags);
void	init_type(const char *format, t_list *info, t_flags *flags);
void	print_char(const char *format, t_list *info, t_flags *flags);
void	print_int(const char *format, t_list *info, t_flags *flags);
void	parse_format(const char *format, t_list *info);
void	parse_flags(const char *format, t_list *info);
void	ft_putchar(char c, t_list *info);
void	conflict_remove(t_flags *flags);
void	flag_zero_fill(t_flags *flags);

size_t	number_len(long number);
//size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
#endif
