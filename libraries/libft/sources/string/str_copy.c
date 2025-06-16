/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:25:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 14:56:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*odst;

	odst = dst;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (odst);
}

char	*ft_strncpy(char *dst, const char *src, size_t length)
{
	char	*odst;

	odst = dst;
	while (*src != 0 && length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	while (length > 0)
	{
		*dst = 0;
		dst++;
		length--;
	}
	return (odst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	const char	*osrc = src;

	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src != 0)
		src++;
	return (src - osrc);
}

char	*ft_strdup(const char *src)
{
	const char	*osrc = src;
	char		*str;

	while (*src != 0)
		src++;
	str = (char *) malloc(src - osrc + 1);
	if (str == NULL)
		return (NULL);
	str += src - osrc;
	*str = 0;
	while (src > osrc)
		*--str = *--src;
	return (str);
}

// Before substr is allocated, it is used as a temp variable to store
// the starting position of (str + start), to limit the max length
char	*ft_substr(const char *str, size_t start, size_t length)
{
	const char	*ostr = str;
	char		*substr;

	if (str == NULL)
		return (NULL);
	while (*str != 0)
		str++;
	substr = (char *) ostr + start;
	if (substr > str)
		return (NULL);
	if (substr + length > str)
		length = str - substr;
	str = substr + length;
	substr = (char *) malloc (length + 1);
	if (substr == NULL)
		return (NULL);
	substr += length;
	*substr = 0;
	while (length > 0)
	{
		*--substr = *--str;
		length--;
	}
	return (substr);
}
