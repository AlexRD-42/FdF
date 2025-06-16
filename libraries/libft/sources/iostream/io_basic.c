/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:24:42 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 00:28:21 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

// Hacky but efficient. Warning: DO NOT USE WITH READ-ONLY
ssize_t	ft_putstr(char *str, int fd, uint8_t newline)
{
	ssize_t	bytes;
	size_t	length;

	if (fd < 0 || str == NULL)
		return (-1);
	length = 0;
	while (str[length] != 0)
		length++;
	if (newline != 0)
	{
		str[length] = '\n';
		bytes = write(fd, str, length + 1);
		str[length] = 0;
	}
	else
		bytes = write(fd, str, length);
	return (bytes);
}

// Code duplication for itoa, so far unavoidable
ssize_t	ft_putnbr(int64_t number, int fd)
{
	const int64_t	sign = (number >= 0) - (number < 0);
	char			buffer[32];
	char			*ptr;

	if (fd < 0)
		return (-1);
	ptr = buffer + 31;
	*(--ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign < 0)
		*(--ptr) = '-';
	return (write(fd, ptr, 32 - (buffer - ptr)));
}

ssize_t	ft_putnchar(const char c, size_t length)
{
	size_t			i;
	ssize_t			bytes;
	size_t			buffer[256 / sizeof(size_t)];

	i = 0;
	bytes = 0;
	buffer[0] = (0x0101010101010101 & UINTPTR_MAX) * c;
	while (length > sizeof(size_t) && i < 256 / sizeof(size_t))
		buffer[i++] = buffer[0];
	while (length >= 256)
	{
		bytes += write(1, buffer, 256);
		length -= 256;
	}
	bytes += write(1, buffer, length);
	return (bytes);
}

ssize_t	ft_putbits(const uint8_t byte)
{
	uint64_t	expand;

	expand = (((uint64_t)byte * 0x8040201008040201ULL) >> 7);
	expand = (expand & 0x0101010101010101ULL) | 0x3030303030303030ULL;
	return (write(1, &expand, 8));
}
