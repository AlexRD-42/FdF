/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:39:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:23:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft.h"

void	ft_swap(void *a_void, void *b_void, size_t length)
{
	size_t	buffer[256 / sizeof(size_t)];
	uint8_t	*a;
	uint8_t	*b;

	a = (uint8_t *) a_void;
	b = (uint8_t *) b_void;
	while (length >= 256)
	{
		ft_memcpy(buffer, a, 256);
		ft_memcpy(a, b, 256);
		ft_memcpy(b, buffer, 256);
		a += 256;
		b += 256;
		length -= 256;
	}
	ft_memcpy(buffer, a, length);
	ft_memcpy(a, b, length);
	ft_memcpy(b, buffer, length);
}

void	ft_swap8(void *a, void *b)
{
	char	temp;

	temp = *(uint8_t *) a;
	*(uint8_t *) a = *(uint8_t *) b;
	*(uint8_t *) b = temp;
}

void	ft_swap32(void *a, void *b)
{
	uint32_t	temp;

	temp = *(uint32_t *) a;
	*(uint32_t *) a = *(uint32_t *) b;
	*(uint32_t *) b = temp;
}

void	ft_swap64(void *a, void *b)
{
	uint64_t	temp;

	temp = *(uint64_t *) a;
	*(uint64_t *) a = *(uint64_t *) b;
	*(uint64_t *) b = temp;
}

// Could use t_ptr here
void	ft_reverse(void *array, size_t length, size_t element_size)
{
	uint8_t	*start;
	uint8_t	*end;
	uint8_t	buffer;

	start = (uint8_t *) array;
	end = start + length - 1;
	if (element_size == 1)
	{
		while (start < end)
		{
			buffer = *start;
			*start++ = *end;
			*end-- = buffer;
		}
	}
	while (start < end)
	{
		ft_swap(start, end, element_size);
		start += element_size;
		end -= element_size;
	}
}
