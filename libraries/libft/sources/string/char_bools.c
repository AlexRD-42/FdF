/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:19:19 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:59:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint8_t	ft_isalpha(int32_t c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

uint8_t	ft_isdigit(int32_t c)
{
	return (c >= '0' && c <= '9');
}

uint8_t	ft_isspace(int32_t c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

uint8_t	ft_isprint(int32_t c)
{
	return (c >= ' ' && c <= '~');
}

uint8_t	ft_isascii(int32_t c)
{
	return (!(c >> 7));
}
