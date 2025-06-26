/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_interp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:23:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 17:10:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

__always_inline
float	ft_lerp(float min, float max, float value)
{
	return (min + value / (max - min));
}

// To linearly interpolate between integers efficiently, it'd be beneficial to
// Figure out linspace between float A and float B, pre-calculating dxy and length
// so that x0,x1 and y0,y1 is included and linearly spaced
uint32_t ft_ilerp(int32_t max, int32_t min, int32_t value)
{
	double var = (double) (value - min) / (double) (max - min);
	return ((uint32_t) (var * 0x00FFFFFF));
}
