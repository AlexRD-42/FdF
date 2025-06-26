/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:22:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/10 20:23:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "ft_math.h"

#define F32_PI8 0.392699093
#define F32_PI4 0.785398185
#define F32_PI2 1.57079637
#define F32_PI1 3.14159274
#define F32_PI10 0.314159265358979323846264338327950288419

typedef union
{
	float f;
	int32_t i;
}	t_32;

float	ft_sin(float x)
{
	float x2 = x * x;
	return (x * (1 - x2 * (1.0f / 6.0f) + x2 * x2 * (1.0f / 120.0f)));
}

static inline
float	lerp(float y0, float y1, float dy)
{
	return (y0 + dy * (y1 - y0));
}

float ft_sin(float x)
{
	// float scaled = x * LUT_SCALE;
	// int idx = (int)scaled;
	// float t = scaled - idx;

	// return sin_lut[idx] + t * (sin_lut[idx + 1] - sin_lut[idx]);
}

int main()
{
	float	sin_lut[64];
	double	pi = 3.14159265358979323846264338327950288419;

	for (size_t i = 0; i < 64; i++)
	{
		sin_lut[i] = (double) i / 63;
	}
}
// int	main()
// {
// 	float	sum;
// 	float x, y, i;
// 	size_t	count = 0;

// 	sum = 0;
// 	i = 0;
// 	while (i < F32_PI2)
// 	{
// 		x = sinf(i);
// 		y = ft_sin(i);
// 		sum += x > y ? x - y : y - x;
// 		i += 2 * __FLT_EPSILON__;
// 		count++;
// 	}
// 	printf("%f", sum * __FLT_EPSILON__);
// }