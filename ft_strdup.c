/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artavagy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:08:28 by artavagy          #+#    #+#             */
/*   Updated: 2026/04/01 18:38:52 by artavagy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_strlcpy(char dst[], const char src[], size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*s_copy;

	s_copy = (char *)malloc(ft_strlen(s) + 1);
	if (!s_copy)
		return (NULL);
	ft_strlcpy(s_copy, s, ft_strlen(s) + 1);
	return (s_copy);
}
