/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/14 00:22:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

static
void	*ft_memrcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void + length;

	if ((uintptr_t) dst_void == (uintptr_t) src_void)
		return (dst_void);
	dst = ((char *) dst_void) + length;
	while (length > sizeof(uintptr_t)
		&& (((uintptr_t)dst | (uintptr_t)src) & (sizeof(uintptr_t) - 1)))
	{
		*--dst = *--src;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		dst -= sizeof(uintptr_t);
		src -= sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
		*((uintptr_t *)dst) = *((uintptr_t *)src);
	}
	while (length > 0)
	{
		*--dst = *--src;
		length--;
	}
	return (dst_void);
}

// Could try to pre-calculate the alignment
// Impossible if (dst & mask != src & mask) or (dst ^ src & mask)?
// Regardless, (7 - addr & mask) is how many bytes to align
// Length > length - bytes_to_align
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	if ((uintptr_t) dst_void >= (uintptr_t) src_void)
		return (ft_memrcpy(dst_void, src_void, length));
	dst = (char *) dst_void;
	while (length > sizeof(uintptr_t)
		&& (((uintptr_t)dst | (uintptr_t)src) & (sizeof(uintptr_t) - 1)))
	{
		*dst++ = *src++;
		length--;
	}
	while (length >= sizeof(uintptr_t))
	{
		*((uintptr_t *)dst) = *((uintptr_t *)src);
		dst += sizeof(uintptr_t);
		src += sizeof(uintptr_t);
		length -= sizeof(uintptr_t);
	}
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}
