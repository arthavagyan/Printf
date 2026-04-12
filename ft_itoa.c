/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:40:29 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 19:54:44 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	number_len1(long number)
{
	long	n;
	size_t	len;

	n = number;
	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	if_negative(long *number, int *sign)
{
	if (*number < 0)
	{
		*number *= -1;
		*sign = -1;
	}
}

char	*ft_itoa(long n)
{
	long	number;
	int		sign;
	size_t	len;
	char	*result;

	number = n;
	sign = 1;
	len = number_len1(number);
	if_negative (&number, &sign);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	if (sign == -1)
		result[0] = '-';
	while (number > 0)
	{
		result[len - 1] = number % 10 + '0';
		number /= 10;
		len--;
	}
	return (result);
}
