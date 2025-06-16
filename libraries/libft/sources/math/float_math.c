/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:28:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 16:19:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <libft_types.h>

// This is faster than receiving a t_32 (thank god)
float	ft_qinvsqrt(float number)
{
	t_32	result;

	result.f = number;
	result.ui = 0x5f3759df - (result.ui >> 1);
	result.f = result.f * (1.5f - (number * 0.5f * result.f * result.f));
	return (result.f);
}

float	ft_qsqrt(float number)
{
	t_32	result;

	result.f = number;
	result.ui = (result.ui >> 1) + 0x1FBD3EE0;
	result.f = 0.5f * (result.f + number / result.f);
	return (result.f);
}

// Check length division
float	ft_average(float *array, size_t length)
{
	float	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (i < length)
	{
		sum += *array;
		array++;
		i++;
	}
	return (sum / (float) length);
}
