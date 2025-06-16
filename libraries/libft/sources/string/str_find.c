/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:31:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 18:44:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, unsigned char c)
{
	if (c == 0)
	{
		while (*str != 0)
			str++;
		return ((char *) str);
	}
	while (*str != 0)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

// This needs to be tested
char	*ft_strrchr(const char *str, unsigned char c)
{
	const char	*end = str;

	while (*end != 0)
		end++;
	if (c == 0)
		return ((char *) end);
	while (--end >= str)
	{
		if (*end == c)
			return ((char *) end);
	}
	return (NULL);
}

// This can be improved
char	*ft_strfind(const char *str, const char *charset, unsigned char ref)
{
	unsigned char	lookup_table[256];

	ft_memset(lookup_table, ref, 256);
	while (*charset != 0)
	{
		lookup_table[(unsigned char) *charset] = !ref;
		charset++;
	}
	lookup_table[0] = 0;
	while (lookup_table[(unsigned char) *str] != 0)
		str++;
	if (*str != 0)
		return ((char *) str);
	return (NULL);
}

char	*ft_strstr(const char *str, const char *substr)
{
	size_t	substr_len;

	if (*substr == 0)
		return ((char *) str);
	substr_len = ft_strlen(substr);
	while (*str != 0)
	{
		if (ft_strncmp(str, substr, substr_len) == 0)
			return ((char *) str);
		str++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *str, const char *substr, size_t length)
{
	size_t	substr_len;
	size_t	str_len;

	if (*substr == 0)
		return ((char *) str);
	substr_len = ft_strlen(substr);
	str_len = ft_strlen(str);
	if (length > str_len)
		length = str_len;
	while (length >= substr_len)
	{
		if (ft_strncmp(str, substr, substr_len) == 0)
			return ((char *) str);
		str++;
		length--;
	}
	return (NULL);
}
