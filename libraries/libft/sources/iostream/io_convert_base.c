/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:58:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:30:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <libft.h>

int64_t	ft_atoi_base(const char *str, const char *base)
{
	const uint8_t	*start = (uint8_t *) ft_strfind(str, base, 1);
	const int64_t	radix = ft_strlen(base);
	const uint64_t	sign = (((char *)start > str) && (*(start - 1) == '-')) - 1;
	int64_t			number;
	uint8_t			lookup_table[256];

	ft_memset(lookup_table, 255, 256);
	number = -1;
	while (++number < radix)
		lookup_table[(uint8_t) base[(size_t) number]] = number;
	number = 0;
	while (*start && lookup_table[*start] < 255)
		number = number * radix - lookup_table[*start++];
	return ((number ^ sign) - sign);
}

char	*ft_itoa_base(const int64_t number, const char *base)
{
	const int64_t	sign = (number >> 63);
	const int64_t	radix = ft_strlen(base);
	char			str[66];
	char			*ptr;
	uint64_t		abs_num;

	if (radix < 2)
		return (NULL);
	abs_num = (uint64_t)((number ^ sign) - sign);
	ptr = str + 65;
	*ptr = 0;
	if (abs_num == 0)
		*(--ptr) = base[(abs_num % radix)];
	while (abs_num != 0)
	{
		*(--ptr) = base[(abs_num % radix)];
		abs_num /= radix;
	}
	if (sign != 0)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}
